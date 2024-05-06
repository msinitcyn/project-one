#include <cairo-xlib.h>

#include "screen_navigation/overlay_window/cairo_renderer.h"

namespace ProjectOne::ScreenNavigation::OverlayWindow {

    CairoRenderer::CairoRenderer(Display* display, Window overlay, XVisualInfo visualInfo, int width, int height)
        : surface(nullptr), cairo(nullptr) {
            this->width = width;
            this->height = height;
            surface = cairo_xlib_surface_create(display, overlay, visualInfo.visual, width, height);
            cairo = cairo_create(surface);
        }

    CairoRenderer::~CairoRenderer() {
        cairo_destroy(cairo);
        cairo_surface_destroy(surface);
    }

    void CairoRenderer::render(ScreenSector& screen_sector) {
        cairo_set_source_rgba(cairo, 1.0, 0.0, 0.0, 0.5);
        cairo_rectangle(cairo, 0, 0, width, height);
        cairo_fill(cairo);

        cairo_set_source_rgba(cairo, 0.0, 1.0, 0.0, 1.0);

        cairo_set_font_size(cairo, 20);
        cairo_select_font_face(cairo, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);

        for (ScreenSector sector : screen_sector.inner_sectors) {
            cairo_move_to(cairo, width*(sector.x+sector.width/2), height*(sector.y+sector.height/2));
            cairo_show_text(cairo, sector.name.c_str());
        }
    }
}
