#pragma once

#include "screen_navigation/screen_sector.h"

namespace ProjectOne::ScreenNavigation::OverlayWindow {
    class OverlayWindow {
    public:
        virtual void draw(ScreenSector& screen_sector) = 0;
        virtual void hide() = 0;

        virtual int get_width() = 0;
        virtual int get_height() = 0;

        virtual ~OverlayWindow() {
        }
    };
}
