#pragma once

#include <X11/Xlib.h>

#include "mouse/mouse_manipulator.h"
#include "x11/x11_screen_info.h"

using namespace ProjectOne::Mouse;

namespace ProjectOne::X11::Mouse::Uinput {
    class UinputMouseManipulatorImpl : public MouseManipulator {
    public:
        UinputMouseManipulatorImpl(X11ScreenInfo& x11ScreenInfo);

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
