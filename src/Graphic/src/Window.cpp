#include "Window.hpp"
#include <System/Log.hpp>

#include <unistd.h>

namespace Graphic {
    MyWindow::MyWindow(int __width, int __height, std::string __title, bool __createFullscreen)
        : _width(__width), _height(__height), _title(__title) {
        #if defined(__linux__)
        _pDisplay = XOpenDisplay(nullptr);
        if (_pDisplay == nullptr) {
            System::logCritical("Window", "can't create X-11 device");
        }

        int screen = DefaultScreen(_pDisplay);
        _window = XCreateSimpleWindow(
            _pDisplay,
            RootWindow(_pDisplay, screen),
            100, 100,
            __width, __height,
            0, 0, WhitePixel(_pDisplay, screen)
        );

        XMapWindow(_pDisplay, _window);

        XFlush(_pDisplay);

        sleep(5);

        #endif
    }

    MyWindow::~MyWindow() {
        #if defined(__linux__)
        XDestroyWindow(_pDisplay, _window);
        XCloseDisplay(_pDisplay);
        #endif
    }

    void MyWindow::draw() {
        
    }
}