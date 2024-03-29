#pragma once

#include "screen_map_builder.h"

namespace ProjectOne::Screen {
    class ScreenMapBuilderImpl: public ScreenMapBuilder {
    public:
        ScreenMap build() override;

        ~ScreenMapBuilderImpl() override {
        }
    };
}
