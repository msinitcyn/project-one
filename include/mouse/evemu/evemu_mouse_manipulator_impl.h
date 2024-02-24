// evemu_mouse_manipulator_impl.h

#pragma once

#include "evemu_command_builder.h"
#include "../mouse_manipulator.h"

namespace ProjectOne::Mouse::Evemu {
    class EvemuMouseManipulatorImpl : public MouseManipulator {
        const int BIG_NEGATIVE_X_SHIFT = -2000;
        const int BIG_NEGATIVE_Y_SHIFT = -2000;

        EvemuCommandBuilder* evemuCommandBuilder;

    public:

        EvemuMouseManipulatorImpl(EvemuCommandBuilder& evemuCommandBuilder);

        void move_at(int x, int y) override;

        void move(int delta_x, int delta_y) override;

        void click() override;

        ~EvemuMouseManipulatorImpl() override {
        }
    };
}
