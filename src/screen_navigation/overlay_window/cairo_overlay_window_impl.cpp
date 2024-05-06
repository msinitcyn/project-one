#include <iostream>
#include <stdio.h>
#include <X11/X.h>
#include <X11/Xutil.h>
#include <cstdlib>

#include <unistd.h>

#include <cairo-xlib.h>

#include "screen_navigation/overlay_window/cairo_renderer.h"
#include "screen_navigation/overlay_window/cairo_overlay_window_impl.h"

namespace ProjectOne::ScreenNavigation::OverlayWindow {

    CairoOverlayWindowImpl::CairoOverlayWindowImpl(X11ScreenInfo& screenInfo) {
        display = screenInfo.get_display();
        width = screenInfo.get_width();
        height = screenInfo.get_height();
    }

    void CairoOverlayWindowImpl::draw(ScreenSector& screenSector) {
        Window root = DefaultRootWindow(display);

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

        std::cout << "window dimensions:" << width << " " << height << std::endl;

        XMapWindow(display, overlay);

        CairoRenderer cairoRenderer(display, overlay, vinfo, width, height);
        cairoRenderer.render(screenSector);

        XFlush(display);
    }

    void CairoOverlayWindowImpl::hide() {
        XUnmapWindow(display, overlay);
        XCloseDisplay(display);
        width = -1;
        height = -1;
    }

    int CairoOverlayWindowImpl::get_width() {
        return width;
    }

    int CairoOverlayWindowImpl::get_height() {
        return height;
    }
}
