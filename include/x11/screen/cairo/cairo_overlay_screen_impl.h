#pragma once

#include <X11/Xlib.h>
#include "screen/overlay_screen.h"
#include "x11/x11_screen_info.h"

using namespace ProjectOne::Screen;

namespace ProjectOne::X11::Screen::Cairo {

    class CairoOverlayScreenImpl : public OverlayScreen {
    public:
        CairoOverlayScreenImpl(X11ScreenInfo& screenInfo);

        void draw(ScreenMap& screenMap) override;
        void hide() override;

        ScreenPoint get_sector_center(ScreenSector& screenSector) override;
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
