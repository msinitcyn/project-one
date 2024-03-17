#include "screen/screen_map_builder_impl.h"

namespace ProjectOne::Screen {
    ScreenMap ScreenMapBuilderImpl::build() {
        ScreenMap result;
        ScreenSector test_sector("q", 0.1, 0.1, 0.1, 0.1);
        result.sectors.push_back(test_sector);
        ScreenSector test_sector1("w", 0.2, 0.1, 0.1, 0.1);
        result.sectors.push_back(test_sector1);
        return result; }
}
