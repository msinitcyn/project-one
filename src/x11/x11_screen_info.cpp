#include "x11/x11_screen_info.h"

namespace ProjectOne::X11 {

    X11ScreenInfo::X11ScreenInfo() {
        display = XOpenDisplay(NULL);
        int snum = DefaultScreen(display);
        width = DisplayWidth(display, snum);
        height = DisplayHeight(display, snum);
    }

    Display* X11ScreenInfo::get_display() {
        return display;
    }

    int X11ScreenInfo::get_height() {
        return height;
    }

    int X11ScreenInfo::get_width() {
        return width;
    }
}
