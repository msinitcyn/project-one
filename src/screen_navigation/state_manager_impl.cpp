#include "screen_navigation/state_manager_impl.h"
#include <unistd.h>

namespace ProjectOne::ScreenNavigation {
    StateManagerImpl::StateManagerImpl(ScreenMapBuilder& screen_builder) : screen_builder(screen_builder), states(0) {
        reset();
    }

    ScreenSector& StateManagerImpl::get_current_state() {
        return states[current_state];
    }

    void StateManagerImpl::reset() {
        ScreenSector root = screen_builder.build(0,0,1,1);
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
        ScreenSector current = get_current_state();
        ScreenSector* target_sector = current.find_child(sector_key);
        if (target_sector) {
            ScreenSector new_root(nullptr, current.x, current.y, current.width, current.height);
            ScreenSector new_child = screen_builder.build(target_sector->x, target_sector->y, target_sector->width, target_sector->height);
            new_root.add_child("some", new_child);

            current_state++;
            if ((int)states.size() >= current_state) {
                states.push_back(new_root);
            } else {
                states[current_state] = new_root;
            }
        }
    }
}
