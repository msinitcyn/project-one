#include <iostream>
#include <stdio.h>
#include <X11/X.h>
#include <X11/Xutil.h>
#include <cstdlib>

#include <unistd.h>

#include <cairo-xlib.h>

#include "screen/cairo/cairo_renderer.h"
#include "screen/cairo/cairo_overlay_screen_impl.h"

namespace ProjectOne::Screen::Cairo {

    void CairoOverlayScreenImpl::draw(ScreenMap& screenMap) {
        display = XOpenDisplay(NULL);
        int snum;
        snum = DefaultScreen(display);
        width = DisplayWidth(display, snum);
        height = DisplayHeight(display, snum);
        Window root = DefaultRootWindow(display);

        // these two lines are really all you need
        XSetWindowAttributes attrs;
        attrs.override_redirect = true;

        XVisualInfo vinfo;
        if (!XMatchVisualInfo(display, DefaultScreen(display), 32, TrueColor, &vinfo)) {
            printf("No visual found supporting 32 bit color, terminating\n");
            exit(EXIT_FAILURE);
        }
        attrs.colormap = XCreateColormap(display, root, vinfo.visual, AllocNone);
        attrs.background_pixel = 0;
        attrs.border_pixel = 0;

        overlay = XCreateWindow(
            display, root,
            0, 0, width, height, 0,
            vinfo.depth, InputOutput, 
            vinfo.visual,
            CWOverrideRedirect | CWColormap | CWBackPixel | CWBorderPixel, &attrs
        );

        XMapWindow(display, overlay);

        CairoRenderer cairoRenderer(display, overlay, vinfo, width, height);
        cairoRenderer.render(screenMap);

        XFlush(display);
    }

    void CairoOverlayScreenImpl::hide() {
        XUnmapWindow(display, overlay);
        XCloseDisplay(display);
        width = -1;
        height = -1;
    }

    int CairoOverlayScreenImpl::get_width() {
        return width;
    }

    int CairoOverlayScreenImpl::get_height() {
        return height;
    }
}
