#include <unistd.h>
#include <iostream>
#include <string>

#include "screen/cairo/cairo_overlay_screen_impl.h"
#include "mouse/evemu/evemu_command_builder_impl.h"
#include "screen/screen_map.h"
#include "mouse/evemu/evemu_mouse_manipulator_impl.h"
#include "screen/screen_map_builder.h"
#include "screen/screen_map_builder_impl.h"

using std::cin;
using std::string;
using namespace ProjectOne::Screen;

namespace ProjectOne {

    void run(Screen::OverlayScreen& overlayScreen, Mouse::MouseManipulator& mouseManipulator, Screen::ScreenMapBuilder& screenMapBuilder) {
        // settings = settingsBuilder.build();
        // overlayScreen.show(settings);
        ScreenMap screenMap = screenMapBuilder.build();
        overlayScreen.draw(screenMap);
        //mouseManipulator.move_at(100, 100);
        //for (int i = 0; i < 100; ++i) {
        //    mouseManipulator.move(1,1);
        //    usleep(10000);
        //}
 //       mouseManipulator.click();
 
        char userInput;
        while (true) {
            cin >> userInput;

            string sectorName = string(1, userInput);

            std::cout << sectorName << std::endl;

            ScreenSector* screenSector = screenMap.find(sectorName);
            if (screenSector) {
                int x = overlayScreen.get_width()*screenSector->x;
                int y = overlayScreen.get_height()*screenSector->y;

                std::cout << x << " " << y << std::endl;
                mouseManipulator.move_at(x, y);
            }

        }
        overlayScreen.hide();
    }

}

int main() {
    ProjectOne::Screen::Cairo::CairoOverlayScreenImpl cairoOverlayScreenImpl;
    ProjectOne::Mouse::Evemu::EvemuCommandBuilderImpl evemuCommandBuilderImpl;
    ProjectOne::Mouse::Evemu::EvemuMouseManipulatorImpl mouseManipulatorImpl(evemuCommandBuilderImpl);
    ProjectOne::Screen::ScreenMapBuilderImpl screenMapBuilderImpl;

    ProjectOne::run(cairoOverlayScreenImpl, mouseManipulatorImpl, screenMapBuilderImpl);
    return 0;
}
