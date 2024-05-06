#pragma once

#include "screen.h"
#include "x11_screen_info.h"

namespace ProjectOne::ScreenNavigation {
    class X11ScreenImpl : public Screen {
    public:
        X11ScreenImpl(X11ScreenInfo& screen_info);

        ScreenPoint get_screen_sector_center(ScreenSector& screen_sector) override;

        ~X11ScreenImpl() override {
        }

    private:
        int width;
        int height;
    };
}
