#include <unistd.h>
#include <iostream>
#include <string>

#include <iostream>
#include <termios.h>
#include <unistd.h>

#include "screen_navigation/overlay_window/overlay_window.h"
#include "screen_navigation/x11_screen_impl.h"
#include "screen_navigation/x11_screen_info.h"
#include "screen_navigation/overlay_window/cairo_overlay_window_impl.h"
#include "screen_navigation/mouse/uinput_mouse_manipulator_impl.h"
#include "screen_navigation/screen_map_builder_impl.h"

using std::cin;
using std::string;

using namespace ProjectOne::ScreenNavigation;
using namespace ProjectOne::ScreenNavigation::Mouse;
using namespace ProjectOne::ScreenNavigation::OverlayWindow;

char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror ("tcsetattr ~ICANON");
    return (buf);
}

    void run(ProjectOne::ScreenNavigation::Screen& screen, ProjectOne::ScreenNavigation::OverlayWindow::OverlayWindow& overlay_window, MouseManipulator& mouseManipulator, ScreenMapBuilder& screenMapBuilder) {
        ScreenSector rootSector = screenMapBuilder.build();
        overlay_window.draw(rootSector);
 
        while (true) {
            char userInput = getch();

            string sectorName = string(1, userInput);

            std::cout << sectorName << std::endl;

            ScreenSector* screen_sector = rootSector.find(sectorName);
            if (screen_sector) {
                ScreenPoint clickPoint = screen.get_screen_sector_center(*screen_sector);

                std::cout << clickPoint.x << " " << clickPoint.y << std::endl;
                mouseManipulator.move_at(clickPoint.x, clickPoint.y);
            }

        }
        overlay_window.hide();
    }


int main() {
    X11ScreenInfo screenInfo;
    X11ScreenImpl screen(screenInfo);
    CairoOverlayWindowImpl cairoOverlayWindowImpl(screenInfo);
    UinputMouseManipulatorImpl uinputMouseManipulatorImpl(screenInfo);
    ScreenMapBuilderImpl screenMapBuilderImpl;

    run(screen, cairoOverlayWindowImpl, uinputMouseManipulatorImpl, screenMapBuilderImpl);
    return 0;
}
