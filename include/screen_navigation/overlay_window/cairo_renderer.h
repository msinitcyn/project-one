#pragma once

#include <vector>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "cairo.h"

#include "screen_navigation/screen_sector.h"

using std::vector;

namespace ProjectOne::ScreenNavigation::OverlayWindow {
    class CairoRenderer {
    public:
        CairoRenderer(Display* display, Window overlay, XVisualInfo visual_info, int screen_width, int screen_height);
        ~CairoRenderer();

        void render(vector<ScreenSector*>& screen_sectors);

    private:
        void iterate_screen_sector(ScreenSector& screen_sector, float w, float h, float x, float y);

        cairo_surface_t* surface;
        cairo_t* cairo;
        int width;
        int height;
    };
}
