#include <unistd.h>
#include <iostream>
#include <string>

#include <iostream>
#include <termios.h>
#include <unistd.h>

#include "screen_navigation/state_manager_impl.h"
#include "screen_navigation/overlay_window/overlay_window.h"
#include "screen_navigation/x11_screen_impl.h"
#include "screen_navigation/x11_screen_info.h"
#include "screen_navigation/overlay_window/cairo_overlay_window_impl.h"
#include "screen_navigation/mouse/uinput_mouse_manipulator_impl.h"
#include "screen_navigation/screen_map_builder_impl.h"

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

void run(ProjectOne::ScreenNavigation::Screen& screen, ProjectOne::ScreenNavigation::OverlayWindow::OverlayWindow& overlay_window, MouseManipulator& mouse_manipulator, StateManager& state_manager) {
    ScreenSector screen_sector = state_manager.get_current_state();
    overlay_window.draw(screen_sector);
    //char c = getch();
    char c = 'd';
    while (c != '1') {
        if (c == '2') {
            state_manager.go_back();
        } else if (c == '4') {
            mouse_manipulator.click();
            state_manager.reset();
            break;
        } else {
            string search_string(1, c);
            state_manager.go_to(search_string);
        }
        ScreenSector& screen_sector = state_manager.get_current_state();
        //overlay_window.hide();
        overlay_window.draw(screen_sector);
        ScreenPoint point = screen.get_screen_sector_center(screen_sector);
        mouse_manipulator.move_at(point.x, point.y);
    }
}



int main() {
    X11ScreenInfo screenInfo;
    X11ScreenImpl screen(screenInfo);
    CairoOverlayWindowImpl cairoOverlayWindowImpl(screenInfo);
    UinputMouseManipulatorImpl uinputMouseManipulatorImpl(screenInfo);
    ScreenMapBuilderImpl screen_builder;
    StateManagerImpl state_manager(screen_builder);

    run(screen, cairoOverlayWindowImpl, uinputMouseManipulatorImpl, state_manager);
    return 0;
}
