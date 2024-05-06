#pragma once

#include "state.h"

namespace ProjectOne::ScreenNavigation {
    class StateManager {
    public:
        virtual ~StateManager() {
        }

        virtual void add(State& state);

        virtual State* step_back();

        virtual State* step_forward();
    };
}
