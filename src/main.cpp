#include "screen/cairo/cairo_overlay_screen_impl.h"
#include "mouse/evemu/evemu_command_builder_impl.h"
#include "mouse/evemu/evemu_mouse_manipulator_impl.h"

namespace ProjectOne {

    void run(Screen::OverlayScreen& overlayScreen, Mouse::MouseManipulator& mouseManipulator) {
        overlayScreen.draw();
        mouseManipulator.move(100, 100);
        mouseManipulator.click();
    }

}

int main() {
    ProjectOne::Screen::Cairo::CairoOverlayScreenImpl cairoOverlayScreenImpl;
    ProjectOne::Mouse::Evemu::EvemuCommandBuilderImpl evemuCommandBuilderImpl;
    ProjectOne::Mouse::Evemu::EvemuMouseManipulatorImpl mouseManipulatorImpl(evemuCommandBuilderImpl);

    ProjectOne::run(cairoOverlayScreenImpl, mouseManipulatorImpl);
    return 0;
}
