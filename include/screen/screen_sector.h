#pragma once

#include <string>

using std::string;

namespace ProjectOne::Screen {
    struct ScreenSector {
        string name;
        float x;
        float y;
        float width;
        float height;

        ScreenSector(const std::string& n, float x_value, float y_value, float width_value, float height_value)
            : name(n), x(x_value), y(y_value), width(width_value), height(height_value) {
        }
    };
}
