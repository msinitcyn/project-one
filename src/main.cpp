#include <unistd.h>
#include <iostream>
#include <string>

#include "x11/mouse/uinput/uinput_mouse_manipulator_impl.h"
#include "x11/screen/cairo/cairo_overlay_screen_impl.h"
#include "screen/screen_map.h"
#include "screen/screen_map_builder.h"
#include "screen/screen_map_builder_impl.h"

#include <iostream>
#include <termios.h>
#include <unistd.h>

using std::cin;
using std::string;

using namespace ProjectOne::Screen;
using namespace ProjectOne::X11;
using namespace ProjectOne::X11::Screen::Cairo;
using namespace ProjectOne::X11::Mouse::Uinput;

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

    void run(OverlayScreen& overlayScreen, MouseManipulator& mouseManipulator, ScreenMapBuilder& screenMapBuilder) {
        // settings = settingsBuilder.build();
        // overlayScreen.show(settings);
        ScreenMap screenMap = screenMapBuilder.build();
        overlayScreen.draw(screenMap);
        //mouseManipulator.move_at(100, 100);
        //for (int i = 0; i < 100; ++i) {
        //    mouseManipulator.move(1,1);
        //    usleep(10000);
        //}
 //       mouseManipulator.click();
 
//        mouseManipulator.move_at(1920, 1080);
//        char userInput;
        while (true) {
            char userInput = getch();
//            cin >> userInput;

            string sectorName = string(1, userInput);

            std::cout << sectorName << std::endl;

            ScreenSector* screenSector = screenMap.find(sectorName);
            if (screenSector) {
                ScreenPoint clickPoint = overlayScreen.get_sector_center(*screenSector);

                std::cout << clickPoint.x << " " << clickPoint.y << std::endl;
                mouseManipulator.move_at(clickPoint.x, clickPoint.y);
            }

        }
        overlayScreen.hide();
    }


int main() {
    X11ScreenInfo screenInfo;
    CairoOverlayScreenImpl cairoOverlayScreenImpl(screenInfo);
    UinputMouseManipulatorImpl uinputMouseManipulatorImpl(screenInfo);
    ProjectOne::Screen::ScreenMapBuilderImpl screenMapBuilderImpl;

    run(cairoOverlayScreenImpl, uinputMouseManipulatorImpl, screenMapBuilderImpl);
    return 0;
}


