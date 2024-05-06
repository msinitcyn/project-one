#include "screen_navigation/x11_screen_impl.h"

namespace ProjectOne::ScreenNavigation {
    X11ScreenImpl::X11ScreenImpl(X11ScreenInfo& screen_info) {
        width = screen_info.get_width();
        height = screen_info.get_height();
    }

    ScreenPoint X11ScreenImpl::get_screen_sector_center(ScreenSector& screen_sector) {
        ScreenPoint result;
        result.x = width * (screen_sector.x + screen_sector.width/2);
        result.y = height * (screen_sector.y + screen_sector.height/2);
        return result;
    }
}
