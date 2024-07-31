#pragma once

#include "state_manager.h"

namespace ProjectOne::ScreenNavigation {
    class Command {
    public:
        virtual void execute(StateManager& state_manager) = 0;

        virtual ~Command() {
        }
    };
}
