#pragma once

#include <X11/Xlib.h>

namespace ProjectOne::ScreenNavigation {
    class X11ScreenInfo {
    public:
        X11ScreenInfo();

        Display* get_display();

        int get_screen_num();

        int get_width();

        int get_height();

    private:
        Display* display;
        int width;
        int height;
    };
}
