#include <string>

#include "screen_navigation/screen_sector.h"

using std::string;

namespace ProjectOne::ScreenNavigation {
    ScreenSector* ScreenSector::find(string sectorName) {
        for (ScreenSector& sector : inner_sectors) {
            if (sector.name == sectorName) {
                return &sector;
            }
        }
        return nullptr;
    }
}
