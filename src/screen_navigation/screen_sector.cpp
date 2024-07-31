#include <string>

#include "screen_navigation/screen_sector.h"

using std::string;

namespace ProjectOne::ScreenNavigation {
    ScreenSector::ScreenSector() {
    }

    ScreenSector::ScreenSector(ScreenSector* parent, float x_value, float y_value, float width_value, float height_value)
        : x(x_value), y(y_value), width(width_value), height(height_value) {
        this->parent = parent;
    }

    ScreenSector* ScreenSector::find_child(const string& key) {
        if (inner_sectors.find(key) != inner_sectors.end())
            return inner_sectors[key];
        return nullptr;
    }

    void ScreenSector::add_child(const string& key, ScreenSector& child) {
        inner_sectors[key] = &child;
    }

    ScreenSector* ScreenSector::get_parent() {
        return parent;
    }
}
