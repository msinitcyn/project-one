#pragma once

namespace ProjectOne::ScreenNavigation {
    class ScreenInfo {
    public:
        virtual int get_width() = 0;
        virtual int get_height() = 0;

        virtual ~ScreenInfo() {
        }
    };
}
