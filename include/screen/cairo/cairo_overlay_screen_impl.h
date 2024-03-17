#pragma once

#include <X11/Xlib.h>
#include "screen/overlay_screen.h"

namespace ProjectOne::Screen::Cairo {
    class CairoOverlayScreenImpl : public OverlayScreen {
    public:
        void draw(ScreenMap& screenMap) override;
        void hide() override;

        int get_width() override;
        int get_height() override;

        ~CairoOverlayScreenImpl() override {
        }

    private:
        int width;
        int height;
        Display *display; 
        Window overlay;

    };
}
