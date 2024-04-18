#pragma once

#include "screen/screen_map.h"
#include "screen/screen_point.h"

namespace ProjectOne::Screen {
    class OverlayScreen {
    public:
        virtual void draw(ScreenMap& screenMap) = 0;
        virtual void hide() = 0;

        virtual ScreenPoint get_sector_center(ScreenSector& screenSector) = 0;

        virtual int get_width() = 0;
        virtual int get_height() = 0;

        virtual ~OverlayScreen() {
        }
    };
}
