#pragma once

#include "screen/screen_map.h"

namespace ProjectOne::Screen {
    class OverlayScreen {
    public:
        virtual void draw(ScreenMap& screenMap) = 0;
        virtual void hide() = 0;

        virtual int get_width() = 0;
        virtual int get_height() = 0;

        virtual ~OverlayScreen() {
        }
    };
}
