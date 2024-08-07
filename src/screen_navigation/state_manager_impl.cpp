#include "screen_navigation/state_manager_impl.h"
#include <unistd.h>

namespace ProjectOne::ScreenNavigation {
    StateManagerImpl::StateManagerImpl(ScreenMapBuilder& screen_builder, ScreenInfo& screen_info) : screen_builder(screen_builder), screen_info(screen_info), states(0) {
        reset();
    }

    vector<ScreenSector*> StateManagerImpl::get_current_state() {
        return states[current_state];
    }

    void StateManagerImpl::reset() {
        vector<ScreenSector*> root = screen_builder.build(0, 0, screen_info.get_width(), screen_info.get_height());
        current_state = 0;
        if (!states.size()) {
            states.push_back(root);
        } else {
            states[current_state] = root;
        }
    }

    void StateManagerImpl::go_back() {
        if (current_state > 0) current_state--;
    }

    void StateManagerImpl::go_to(string sector_key) {
        vector<ScreenSector*> current = get_current_state();
        ScreenSector* target = nullptr;
        for (ScreenSector* screen_sector : current) {
            if (screen_sector->content == sector_key) {
                target = screen_sector;
                break;
            }
        }
        if (target) {
            vector<ScreenSector*> next = screen_builder.build(target->x, target->y, target->width, target->height);
            current_state++;
            if ((int)states.size() <= current_state) {
                states.push_back(next);
            } else {
                states[current_state] = next;
            }
        }
    }
}
