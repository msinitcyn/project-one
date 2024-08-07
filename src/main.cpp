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

void run(ProjectOne::ScreenNavigation::OverlayWindow::OverlayWindow& overlay_window, MouseManipulator& mouse_manipulator, StateManager& state_manager) {
    state_manager.reset();
    while (true) {
        vector<ScreenSector*> screen_sectors = state_manager.get_current_state();
        int x = screen_sectors[0]->x;
        int y = screen_sectors[0]->y;
        mouse_manipulator.move_at(x, y);
        overlay_window.draw(screen_sectors);
        char c = getch();
        //char c = 'd';
        if (c == '2') {
            state_manager.go_back();
        } else if (c == '3') {
            overlay_window.hide();
            mouse_manipulator.click();
            //break;
        } else if (c == '4') {
            break;
        } else {
            string search_string(1, c);
            state_manager.go_to(search_string);
        }
    }
}


int main() {
    X11ScreenInfo screen_info;
    CairoOverlayWindowImpl cairoOverlayWindowImpl(screen_info);
    UinputMouseManipulatorImpl uinputMouseManipulatorImpl(screen_info);
    ScreenMapBuilder screen_builder;
    StateManagerImpl state_manager(screen_builder, screen_info);

    run(cairoOverlayWindowImpl, uinputMouseManipulatorImpl, state_manager);
    return 0;
}
