#pragma once

#include "screen_map.h"

namespace ProjectOne::Screen {
    class ScreenMapBuilder {
    public:
        virtual ScreenMap build(int width, int height) = 0;

        virtual ~ScreenMapBuilder() {
        }
    };
}
