#pragma once

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "cairo.h"

#include "screen_navigation/screen_sector.h"

namespace ProjectOne::ScreenNavigation::OverlayWindow {
    class CairoRenderer {
    public:
        CairoRenderer(Display* display, Window overlay, XVisualInfo visual_info, int screen_width, int screen_height);
        ~CairoRenderer();

        void render(ScreenSector& screen_sector);

    private:
        cairo_surface_t* surface;
        cairo_t* cairo;
        int width;
        int height;
    };
}
