#include <string>
#include <cstdlib>
#include <linux/input.h>

#include "mouse/evemu/evemu_mouse_manipulator_impl.h"

using std::string;

namespace ProjectOne::Mouse::Evemu {

    EvemuMouseManipulatorImpl::EvemuMouseManipulatorImpl(EvemuCommandBuilder& evemuCommandBuilder) {
        this->evemuCommandBuilder = &evemuCommandBuilder;
    }
    void EvemuMouseManipulatorImpl::move_at(int x, int y) {
        move(BIG_NEGATIVE_X_SHIFT, BIG_NEGATIVE_Y_SHIFT);
        move(x, y);
    }

    void EvemuMouseManipulatorImpl::move(int delta_x, int delta_y) {
        string move_x_command = evemuCommandBuilder->build("event6", EV_REL, REL_X, delta_x);
        system(move_x_command.c_str());
        string move_y_command = evemuCommandBuilder->build("event6", EV_REL, REL_Y, delta_y);
        system(move_y_command.c_str());
    }

    void EvemuMouseManipulatorImpl::click() {
        string click_command = evemuCommandBuilder->build("event6", EV_KEY, BTN_LEFT, 1);
        system(click_command.c_str());
    }
};
