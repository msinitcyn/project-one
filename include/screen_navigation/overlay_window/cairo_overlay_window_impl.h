#pragma once

#include <X11/Xlib.h>

#include "overlay_window.h"
#include "screen_navigation/x11_screen_info.h"

namespace ProjectOne::ScreenNavigation::OverlayWindow {

    class CairoOverlayWindowImpl : public OverlayWindow {
    public:
        CairoOverlayWindowImpl(X11ScreenInfo& screenInfo);

        void draw(ScreenSector& screenSector) override;
        void hide() override;

        int get_width() override;
        int get_height() override;

        ~CairoOverlayWindowImpl() override {
        }

    private:
        int width;
        int height;
        Display *display; 
        Window overlay;
    };
}
