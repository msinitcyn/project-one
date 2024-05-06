#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace ProjectOne::ScreenNavigation {
    class ScreenSector {
    public:
        string name;
        float x;
        float y;
        float width;
        float height;

        vector<ScreenSector> inner_sectors;

        ScreenSector(const string& n, float x_value, float y_value, float width_value, float height_value)
            : name(n), x(x_value), y(y_value), width(width_value), height(height_value) {
        }

        ScreenSector* find(string key);
    };
}
