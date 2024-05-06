#pragma once

#include "screen_sector.h"

namespace ProjectOne::ScreenNavigation {
    class ScreenMapBuilder {
    public:
        virtual ScreenSector build() = 0;

        virtual ~ScreenMapBuilder() {
        }
    };
}
