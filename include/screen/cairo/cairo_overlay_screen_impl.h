#include "screen/overlay_screen.h"

namespace ProjectOne::Screen::Cairo {
    class CairoOverlayScreenImpl : public OverlayScreen {
    public:
        void draw() override;
        void hide() override;

        ~CairoOverlayScreenImpl() override {
        }
    };

}
