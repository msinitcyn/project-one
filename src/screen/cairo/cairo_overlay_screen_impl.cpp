#include <iostream>
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/X.h>
#include <X11/Xutil.h>
#include <cstdlib>

#include <unistd.h>

#include <cairo.h>
#include <cairo-xlib.h>

#include "screen/cairo/cairo_overlay_screen_impl.h"

namespace ProjectOne::Screen::Cairo {

    static void draw1(cairo_t *cr, int width, int height) {
        cairo_set_source_rgba(cr, 1.0, 0.0, 0.0, 0.5);
        cairo_rectangle(cr, 0, 0, width, height);
        cairo_fill(cr);


        cairo_set_source_rgba(cr, 0.0, 1.0, 0.0, 1.0);
        // Set font size and type
        cairo_set_font_size(cr, 20);
        cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);

        // Move to the starting position
        cairo_move_to(cr, 10, 40);

        // Draw text on the surface
        cairo_show_text(cr, "Hello, Cairo!");
    }


    void CairoOverlayScreenImpl::draw() {
        Display *d = XOpenDisplay(NULL);
        int snum;
        snum = DefaultScreen(d);
        int width = DisplayWidth(d, snum);
        int height = DisplayHeight(d, snum);
        std::cout << "Display width:" << width << std::endl;
        std::cout << "Display height:" << height << std::endl;
        Window root = DefaultRootWindow(d);
        int default_screen = XDefaultScreen(d);

        // these two lines are really all you need
        XSetWindowAttributes attrs;
        attrs.override_redirect = true;

        XVisualInfo vinfo;
        if (!XMatchVisualInfo(d, DefaultScreen(d), 32, TrueColor, &vinfo)) {
            printf("No visual found supporting 32 bit color, terminating\n");
            exit(EXIT_FAILURE);
        }
        // these next three lines add 32 bit depth, remove if you dont need and change the flags below
        attrs.colormap = XCreateColormap(d, root, vinfo.visual, AllocNone);
        attrs.background_pixel = 0;
        attrs.border_pixel = 0;

        Window overlay = XCreateWindow(
            d, root,
            0, 0, width, height, 0,
            vinfo.depth, InputOutput, 
            vinfo.visual,
            CWOverrideRedirect | CWColormap | CWBackPixel | CWBorderPixel, &attrs
        );

        XMapWindow(d, overlay);

        cairo_surface_t* surf = cairo_xlib_surface_create(d, overlay,
                                      vinfo.visual,
                                      width, height);
        cairo_t* cr = cairo_create(surf);

        draw1(cr, width, height);

        XWarpPointer(d, None, DefaultRootWindow(d), 0, 0, 0, 0, 300, 400);

        XFlush(d);

        // show the window for 10 seconds
        //std::this_thread::sleep_for(std::chrono::milliseconds(10000));
        usleep(10000);

        cairo_destroy(cr);
        cairo_surface_destroy(surf);

        XUnmapWindow(d, overlay);
        XCloseDisplay(d);

    }

    void CairoOverlayScreenImpl::hide() {

    }
}
