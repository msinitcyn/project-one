#include <cairo-xlib.h>

#include "screen_navigation/overlay_window/cairo_renderer.h"

using std::max;
using std::min;

namespace ProjectOne::ScreenNavigation::OverlayWindow {

    CairoRenderer::CairoRenderer(Display* display, Window overlay, XVisualInfo visual_info, int width, int height)
        : surface(nullptr), cairo(nullptr) {
            this->width = width;
            this->height = height;
            surface = cairo_xlib_surface_create(display, overlay, visual_info.visual, width, height);
            cairo = cairo_create(surface);
        }

    CairoRenderer::~CairoRenderer() {
        cairo_destroy(cairo);
        cairo_surface_destroy(surface);
    }

    void CairoRenderer::render(vector<ScreenSector*>& screen_sectors) {
        cairo_set_source_rgba(cairo, 1.0, 0.0, 0.0, 0.5);
        cairo_rectangle(cairo, 0, 0, width, height);
        cairo_fill(cairo);

        cairo_set_source_rgba(cairo, 0.0, 1.0, 0.0, 1.0);

        int font_size = min(20,screen_sectors[0]->width/2);
        font_size = max(font_size, 4);

        cairo_set_font_size(cairo, font_size);
        cairo_select_font_face(cairo, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
        cairo_set_line_width(cairo, 1.0);

        for (ScreenSector* screen_sector : screen_sectors) {
            cairo_move_to(cairo, screen_sector->x+(screen_sector->width-font_size)/2, screen_sector->y+(screen_sector->height-font_size)/2);
            cairo_show_text(cairo, screen_sector->content.c_str());

            cairo_move_to(cairo, screen_sector->x, screen_sector->y);
            cairo_line_to(cairo, screen_sector->x+screen_sector->width, screen_sector->y);
            cairo_stroke(cairo);

            cairo_move_to(cairo, screen_sector->x+screen_sector->width, screen_sector->y);
            cairo_line_to(cairo, screen_sector->x+screen_sector->width, screen_sector->y+screen_sector->height);
            cairo_stroke(cairo);
        }
    }
}
