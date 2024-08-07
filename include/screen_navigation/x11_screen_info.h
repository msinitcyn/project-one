#pragma once

#include <X11/Xlib.h>

#include "screen_info.h"

namespace ProjectOne::ScreenNavigation {
    class X11ScreenInfo : public ScreenInfo {
    public:
        X11ScreenInfo();

        int get_width() override;
        int get_height() override;

        Display* get_display();
        int get_screen_num();

        ~X11ScreenInfo() override {
        }

   private:
        Display* display;
        int width;
        int height;
    };
}
