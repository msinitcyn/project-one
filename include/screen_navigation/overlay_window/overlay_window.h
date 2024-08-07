#pragma once

#include <vector>
#include "screen_navigation/screen_sector.h"

using std::vector;

namespace ProjectOne::ScreenNavigation::OverlayWindow {
    class OverlayWindow {
    public:
        virtual void draw(vector<ScreenSector*>& screen_sectors) = 0;
        virtual void hide() = 0;

        virtual int get_width() = 0;
        virtual int get_height() = 0;

        virtual ~OverlayWindow() {
        }
    };
}
