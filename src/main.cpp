#include <unistd.h>

#include "screen/cairo/cairo_overlay_screen_impl.h"
#include "mouse/evemu/evemu_command_builder_impl.h"
#include "mouse/evemu/evemu_mouse_manipulator_impl.h"

namespace ProjectOne {

    void run(Screen::OverlayScreen& overlayScreen, Mouse::MouseManipulator& mouseManipulator) {
        // settings = settingsBuilder.build();
        // overlayScreen.show(settings);
        overlayScreen.draw();
        mouseManipulator.move_at(100, 100);
        for (int i = 0; i < 100; ++i) {
            mouseManipulator.move(1,1);
            usleep(10000);
        }
 //       mouseManipulator.click();
        overlayScreen.hide();
    }

}

int main() {
    ProjectOne::Screen::Cairo::CairoOverlayScreenImpl cairoOverlayScreenImpl;
    ProjectOne::Mouse::Evemu::EvemuCommandBuilderImpl evemuCommandBuilderImpl;
    ProjectOne::Mouse::Evemu::EvemuMouseManipulatorImpl mouseManipulatorImpl(evemuCommandBuilderImpl);

    ProjectOne::run(cairoOverlayScreenImpl, mouseManipulatorImpl);
    return 0;
}
