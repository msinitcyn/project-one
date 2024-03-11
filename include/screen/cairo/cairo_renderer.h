#pragma once

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "cairo.h"
#include "screen/screen_map.h"

namespace ProjectOne::Screen::Cairo {
    class CairoRenderer {
    public:
        CairoRenderer(Display* display, Window overlay, XVisualInfo visualInfo, int screenWidth, int screenHeight);
        ~CairoRenderer();

        void render(ScreenMap& screenMap);

    private:
        cairo_surface_t* surface;
        cairo_t* cairo;
        int width;
        int height;
    };
}
