#pragma once

#include <X11/Xlib.h>
#include <X11/XF86keysym.h>

#if defined(__linux__)
#define KEY_CODE_A XK_A
#define KEY_CODE_B XK_B
#define KEY_CODE_C XK_C
#define KEY_CODE_D XK_D
#define KEY_CODE_E XK_E
#define KEY_CODE_F XK_F
#define KEY_CODE_G XK_G
#define KEY_CODE_H XK_H
#define KEY_CODE_I XK_I
#define KEY_CODE_J XK_J
#define KEY_CODE_K XK_K
#define KEY_CODE_L XK_L
#define KEY_CODE_M XK_M
#define KEY_CODE_N XK_N
#define KEY_CODE_O XK_O
#define KEY_CODE_P XK_P
#define KEY_CODE_Q XK_Q
#define KEY_CODE_R XK_R
#define KEY_CODE_S XK_S
#define KEY_CODE_T XK_T
#define KEY_CODE_U XK_U
#define KEY_CODE_V XK_V
#define KEY_CODE_W XK_W
#define KEY_CODE_X XK_X
#define KEY_CODE_Y XK_Y
#define KEY_CODE_Z XK_Z

#define KEY_CODE_a XK_a
#define KEY_CODE_b XK_b
#define KEY_CODE_c XK_c
#define KEY_CODE_d XK_d
#define KEY_CODE_e XK_e
#define KEY_CODE_f XK_f
#define KEY_CODE_g XK_g
#define KEY_CODE_h XK_h
#define KEY_CODE_i XK_i
#define KEY_CODE_j XK_j
#define KEY_CODE_k XK_k
#define KEY_CODE_l XK_l
#define KEY_CODE_m XK_m
#define KEY_CODE_n XK_n
#define KEY_CODE_o XK_o
#define KEY_CODE_p XK_p
#define KEY_CODE_q XK_q
#define KEY_CODE_r XK_s
#define KEY_CODE_s XK_s
#define KEY_CODE_t XK_t
#define KEY_CODE_u XK_u
#define KEY_CODE_v XK_v
#define KEY_CODE_w XK_w
#define KEY_CODE_x XK_x
#define KEY_CODE_y XK_y
#define KEY_CODE_z XK_z

#define KEY_CODE_0 XK_0
#define KEY_CODE_1 XK_1
#define KEY_CODE_2 XK_2
#define KEY_CODE_3 XK_3
#define KEY_CODE_4 XK_4
#define KEY_CODE_5 XK_5
#define KEY_CODE_6 XK_6
#define KEY_CODE_7 XK_7
#define KEY_CODE_8 XK_8
#define KEY_CODE_9 XK_9
#endif


namespace Core {
    struct IMWndID;

    class InputManager {
    public:
        InputManager(void *__windowIDPtr);
        ~InputManager() = default;

        void updateEvents();
        bool windowShouldClose() { return _windowShouldClose; }

        void setKeyPressCallback(void (*__keyCallback)(unsigned int));

    private:
        Display* _display = nullptr;
        IMWndID *_id;
        XEvent _event;
        Atom _wmDeleteMessage;

        long _inputMask = 0x0;

        bool _windowShouldClose;

        void (*_keyCallback)(unsigned int);
    };
}