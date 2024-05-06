#pragma once

#include "screen_sector.h"

namespace ProjectOne::ScreenNavigation {
    struct State {
    public:
        int level;
        ScreenSector screen_sector;
    };
}
