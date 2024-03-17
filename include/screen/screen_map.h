#pragma once

#include <vector>
#include <string>

#include "screen_sector.h"

using std::string;
using std::vector;

namespace ProjectOne::Screen {
    class ScreenMap {
    public:
        vector<ScreenSector> sectors;

        ScreenSector* find(string sectorName);
    };
}
