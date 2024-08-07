#pragma once

#include <vector>

#include "screen_sector.h"

using std::vector;

namespace ProjectOne::ScreenNavigation {
    class StateManager {
    public:

        virtual vector<ScreenSector*> get_current_state() = 0;
        virtual void reset() = 0;
        virtual void go_back() = 0;
        virtual void go_to(string sector_key) = 0;

        virtual ~StateManager() {
        }
    };
}
