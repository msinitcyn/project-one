#include "screen/overlay_screen.h"

namespace ProjectOne::Screen::Cairo {
    class CairoOverlayScreenImpl : OverlayScreen {
    public:
        void draw();
        void hide();
    };

}
