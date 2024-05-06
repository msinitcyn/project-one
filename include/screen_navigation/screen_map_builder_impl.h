#pragma once

#include "screen_map_builder.h"

namespace ProjectOne::ScreenNavigation {
    class ScreenMapBuilderImpl: public ScreenMapBuilder {
    public:
        ScreenSector build() override;

        ~ScreenMapBuilderImpl() override {
        }
    };
}
