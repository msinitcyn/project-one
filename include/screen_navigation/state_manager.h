#pragma once

#include "screen_sector.h"

namespace ProjectOne::ScreenNavigation {
    class StateManager {
    public:
        virtual ScreenSector& get_current_state() = 0;
        virtual void reset() = 0;
        virtual void go_back() = 0;
        virtual void go_to(string sector_key) = 0;

        virtual ~StateManager() {
        }
    };
}
