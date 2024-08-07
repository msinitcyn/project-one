#pragma once

#include <string>

using std::string;

namespace ProjectOne::ScreenNavigation {
    struct ScreenSector {
        int x;
        int y;
        int width;
        int height;
        string content;

        ScreenSector(string content, float x_value, float y_value, float width_value, float height_value)
            : x(x_value), y(y_value), width(width_value), height(height_value) {
                this->content = content;
            }
    };
}
