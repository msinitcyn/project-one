#pragma once

#include "screen_sector.h"

namespace ProjectOne::ScreenNavigation {
    class ScreenMapBuilder {
    public:
        virtual ScreenSector build(float x, float y, float width, float height) = 0;

        virtual ~ScreenMapBuilder() {
        }
    };
}
