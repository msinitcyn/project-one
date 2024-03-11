#pragma once

#include <vector>

#include "screen_sector.h"

using std::vector;

namespace ProjectOne::Screen {
    class ScreenMap {
    public:
        vector<ScreenSector> sectors;
    };
}
