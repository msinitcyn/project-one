#include "screen/cairo/cairo_overlay_screen_impl.h"
#include "mouse/evemu/evemu_command_builder_impl.h"
#include "mouse/evemu/evemu_mouse_manipulator_impl.h"

int main() {
    ProjectOne::Screen::Cairo::CairoOverlayScreenImpl cairoOverlayScreenImpl;
    ProjectOne::Mouse::Evemu::EvemuCommandBuilderImpl evemuCommandBuilderImpl;
    ProjectOne::Mouse::Evemu::EvemuMouseManipulatorImpl mouseMainpulator(evemuCommandBuilderImpl);

    //App app;
    //app.run(cairoOverlayScreenImp, mouseMainpulator);
    return 0;
}
