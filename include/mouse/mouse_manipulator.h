// mouse_manipulator.h
#pragma once

namespace ProjectOne::Mouse {
    class MouseManipulator {
    public:
        virtual void move_at(int x, int y) = 0;
        virtual void move(int delta_x, int delta_y) = 0;
        virtual void click() = 0;

        virtual ~MouseManipulator() {
        }
    };
}
