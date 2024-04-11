#include <X11/Xlib.h>

#include <linux/uinput.h>

#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <stdio.h>

#include "mouse/uinput/uinput_mouse_manipulator_impl.h"

using namespace std;

namespace ProjectOne::Mouse::Uinput {

    UinputMouseManipulatorImpl::UinputMouseManipulatorImpl() {
        fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
        ioctl(fd, UI_SET_EVBIT, EV_KEY);
        ioctl(fd, UI_SET_KEYBIT, BTN_RIGHT);
        ioctl(fd, UI_SET_KEYBIT, BTN_LEFT);
        ioctl(fd, UI_SET_EVBIT, EV_ABS);
        ioctl(fd, UI_SET_ABSBIT, ABS_X);
        ioctl(fd, UI_SET_ABSBIT, ABS_Y);
        ioctl(fd, UI_SET_EVBIT, EV_REL);

        struct uinput_user_dev uidev;
        memset(&uidev,0,sizeof(uidev));
        snprintf(uidev.name,UINPUT_MAX_NAME_SIZE,"VirtualMouse");
        uidev.id.bustype = BUS_USB;
        uidev.id.version = 1;
        uidev.id.vendor = 0x1;
        uidev.id.product = 0x1;
        uidev.absmin[ABS_X] = 0;
        uidev.absmax[ABS_X] = 3200;
        uidev.absmin[ABS_Y] = 0;
        uidev.absmax[ABS_Y] = 900;

        write(fd, &uidev, sizeof(uidev));
        ioctl(fd, UI_DEV_CREATE);

        sleep(2);
    }

    void UinputMouseManipulatorImpl::get_position(int& x, int& y) {
        Window root, child;
        int rootX, rootY, winX, winY;
        unsigned int mask;

        XQueryPointer(display, DefaultRootWindow(display),&root,&child,
                      &rootX,&rootY,&winX,&winY,&mask);

        x = rootX;
        y = rootY;
    }

    void UinputMouseManipulatorImpl::move(int delta_x, int delta_y) {
        int x, y;
        get_position(x, y);
        move_at(x+delta_x, y+delta_y);
    }

    void UinputMouseManipulatorImpl::move_at(int x, int y) {
        struct input_event ev[2], ev_sync;
        memset(ev, 0, sizeof(ev));
        memset(&ev_sync, 0, sizeof(ev_sync));

        ev[0].type = EV_ABS;
        ev[0].code = ABS_X;
        ev[0].value = x;
        ev[1].type = EV_ABS;
        ev[1].code = ABS_Y;
        ev[1].value = y;


        int res_w = write(fd, ev, sizeof(ev));

        ev_sync.type = EV_SYN;
        ev_sync.value = 0;
        ev_sync.code = 0;
        int res_ev_sync = write(fd, &ev_sync, sizeof(ev_sync));
    }

    void UinputMouseManipulatorImpl::click() {
        struct input_event ev_click, ev_sync;
        memset(&ev_click, 0, sizeof(ev_click));
        memset(&ev_sync, 0, sizeof(ev_sync));

        ev_click.type = EV_KEY;
        ev_click.code = BTN_LEFT;
        ev_click.value = 1;

        //write left click event
        write(fd, &ev_click, sizeof(ev_click));

        //sync left click event
        ev_sync.type = EV_SYN;
        write(fd, &ev_sync, sizeof(ev_sync));
    }
}
