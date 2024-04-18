#include "screen/screen_map_builder_impl.h"

namespace ProjectOne::Screen {
    ScreenMap ScreenMapBuilderImpl::build() {
        ScreenMap result;
        ScreenSector test_sector("q", 0.0, 0.0, 0.1, 0.3);
        result.sectors.push_back(test_sector);
        ScreenSector test_sector1("w", 0.1, 0.0, 0.1, 0.3);
        result.sectors.push_back(test_sector1);
        ScreenSector test_sector2("e", 0.2, 0.0, 0.1, 0.3);
        result.sectors.push_back(test_sector2);
        ScreenSector test_sector3("a", 0.0, 0.3, 0.1, 0.3);
        result.sectors.push_back(test_sector3);
        ScreenSector test_sector4("s", 0.1, 0.3, 0.1, 0.3);
        result.sectors.push_back(test_sector4);
        return result; }
}
