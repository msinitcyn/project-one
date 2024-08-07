#pragma once

#include "state_manager.h"
#include "screen_map_builder.h"
#include "screen_info.h"
#include <X11/Xlib.h>

namespace ProjectOne::ScreenNavigation {
    class StateManagerImpl : public StateManager {
    public:
        StateManagerImpl(ScreenMapBuilder& screen_builder, ScreenInfo& screen_info);

        vector<ScreenSector*> get_current_state() override;
        void reset() override;
        void go_back() override;
        void go_to(string sector_key) override;

        ~StateManagerImpl() override {
        }

    private:
        ScreenMapBuilder& screen_builder;
        ScreenInfo& screen_info;
        int current_state;
        vector<vector<ScreenSector*>> states;
    };
}
