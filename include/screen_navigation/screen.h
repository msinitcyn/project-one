#pragma once

#include "screen_point.h"
#include "screen_sector.h"

namespace ProjectOne::ScreenNavigation {
    class Screen {
    public:
        virtual ScreenPoint get_screen_sector_center(ScreenSector& screen_sector) = 0;

        virtual ~Screen() {
        }
    };
}
