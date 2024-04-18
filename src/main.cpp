#include <unistd.h>
#include <iostream>
#include <string>

#include "x11/mouse/uinput/uinput_mouse_manipulator_impl.h"
#include "x11/screen/cairo/cairo_overlay_screen_impl.h"
#include "screen/screen_map.h"
#include "screen/screen_map_builder.h"
#include "screen/screen_map_builder_impl.h"

using std::cin;
using std::string;

using namespace ProjectOne::Screen;
using namespace ProjectOne::X11;
using namespace ProjectOne::X11::Screen::Cairo;
using namespace ProjectOne::X11::Mouse::Uinput;

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
 
        mouseManipulator.move_at(1920, 1080);
        char userInput;
        while (true) {
            cin >> userInput;

            string sectorName = string(1, userInput);

            std::cout << sectorName << std::endl;

            ScreenSector* screenSector = screenMap.find(sectorName);
            if (screenSector) {
                ScreenPoint clickPoint = overlayScreen.get_sector_center(*screenSector);

                std::cout << clickPoint.x << " " << clickPoint.y << std::endl;
                mouseManipulator.move_at(clickPoint.x, clickPoint.y);
            }

        }
        overlayScreen.hide();
    }

}

int main() {
    X11ScreenInfo screenInfo;
    CairoOverlayScreenImpl cairoOverlayScreenImpl(screenInfo);
    UinputMouseManipulatorImpl uinputMouseManipulatorImpl(screenInfo);
    ProjectOne::Screen::ScreenMapBuilderImpl screenMapBuilderImpl;

    ProjectOne::run(cairoOverlayScreenImpl, uinputMouseManipulatorImpl, screenMapBuilderImpl);
    return 0;
}
