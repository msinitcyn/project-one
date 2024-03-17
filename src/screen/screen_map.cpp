#include "screen/screen_map.h"

#include <string>

using std::string;

namespace ProjectOne::Screen {
    ScreenSector* ScreenMap::find(string sectorName) {

        for (ScreenSector& sector : sectors) {
            if (sector.name == sectorName) {
                return &sector;
            }
        }

        return nullptr;
    }
}
