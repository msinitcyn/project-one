#pragma once

#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

namespace ProjectOne::ScreenNavigation {
    class ScreenSector {
    public:
        float x;
        float y;
        float width;
        float height;
        map<string, ScreenSector*> inner_sectors;

        ScreenSector();

        ScreenSector(ScreenSector* parent, float x_value, float y_value, float width_value, float height_value);

        ScreenSector* find_child(const string& key);

        void add_child(const string& key, ScreenSector& child);

        ScreenSector* get_parent();

    private:
        ScreenSector* parent;
    };
}
