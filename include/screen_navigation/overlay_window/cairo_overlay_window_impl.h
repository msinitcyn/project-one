#pragma once

#include <X11/Xlib.h>

#include "overlay_window.h"
#include "screen_navigation/x11_screen_info.h"

namespace ProjectOne::ScreenNavigation::OverlayWindow {

    class CairoOverlayWindowImpl : public OverlayWindow {
    public:
        CairoOverlayWindowImpl(X11ScreenInfo& screen_info);

        void draw(ScreenSector& screen_sector) override;
        void hide() override;

        int get_width() override;
        int get_height() override;

        ~CairoOverlayWindowImpl() override {
        }

    private:
        X11ScreenInfo& screen_info;
        int width;
        int height;
        Display* display; 
        Window* overlay;
    };
}
