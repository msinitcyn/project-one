#pragma once

#include <vector>
#include "screen_sector.h"

using std::vector;

namespace ProjectOne::ScreenNavigation {
    class ScreenMapBuilder {
    public:
        vector<ScreenSector*> build(int x, int y, int width, int height);
    };
}
