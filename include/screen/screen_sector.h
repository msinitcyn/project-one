#pragma once

#include <string>

using std::string;

namespace ProjectOne::Screen {
    struct ScreenSector {
        string name;
        int x;
        int y;
        int width;
        int height;
    };
}
