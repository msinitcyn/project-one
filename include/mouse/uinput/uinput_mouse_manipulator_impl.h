// uinput_mouse_manipulator_impl

#pragma once

#include <X11/Xlib.h>

#include "../mouse_manipulator.h"

namespace ProjectOne::Mouse::Uinput {
    class UinputMouseManipulatorImpl : public MouseManipulator {
    public:
        UinputMouseManipulatorImpl();

        void move_at(int x, int y) override;

        void move(int delta_x, int delta_y) override;

        void click() override;

        ~UinputMouseManipulatorImpl() override {
        }

    private:
        int fd;
        Display* display;

        void get_position(int& x, int& y);
    };
}
