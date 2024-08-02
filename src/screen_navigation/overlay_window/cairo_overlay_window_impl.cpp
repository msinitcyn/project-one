#include <iostream>
#include <stdio.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <cstdlib>

#include <unistd.h>

#include <cairo-xlib.h>

#include "screen_navigation/overlay_window/cairo_renderer.h"
#include "screen_navigation/overlay_window/cairo_overlay_window_impl.h"

namespace ProjectOne::ScreenNavigation::OverlayWindow {

    CairoOverlayWindowImpl::CairoOverlayWindowImpl(X11ScreenInfo& screen_info): screen_info(screen_info) {
        overlay = nullptr;
    }

    void CairoOverlayWindowImpl::draw(ScreenSector& screen_sector) {
        try {

            if (screen_sector.inner_sectors.size())
                std::cout << "before: " << screen_sector.inner_sectors.begin()->second->width << std::endl;

            display = screen_info.get_display();
            width = screen_info.get_width();
            height = screen_info.get_height();
     
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

            if (screen_sector.inner_sectors.size())
                std::cout << "after: " << screen_sector.inner_sectors.begin()->second->width << std::endl;

            if (overlay) {
                //XUnmapWindow(display, *overlay);
                //XDestroyWindow(display, *overlay);
            }

            //if (!overlay) {
                //XUnmapWindow(display, *overlay);
                //XDestroyWindow(display, *overlay);
                Window *a;
                *a = XCreateWindow(
                    display, root,
                    0, 0, width, height, 0,
                    vinfo.depth, InputOutput, 
                    vinfo.visual,
                    CWOverrideRedirect | CWColormap | CWBackPixel | CWBorderPixel, &attrs
                );

                if (overlay) {
                    XDestroyWindow(display, *overlay);
                }

                overlay = a;
                //*overlay = overlay1;
                //Window overlay2 = *overlay;
                //int test = 1;
            //}

            std::cout << "window dimensions:" << width << " " << height << std::endl;

            XMapWindow(display, *overlay);

            CairoRenderer cairoRenderer(display, *overlay, vinfo, width, height);
            cairoRenderer.render(screen_sector);

            XFlush(display);
        }
        catch(const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    void CairoOverlayWindowImpl::hide() {
        XUnmapWindow(display, *overlay);
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
