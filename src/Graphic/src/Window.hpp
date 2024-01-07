#pragma once

#include <string>

#include <X11/Xlib.h>

namespace Graphic {
    class MyWindow {
    public:
        MyWindow(int width, int height, std::string title, bool createFullscreen = false);
        ~MyWindow();

        void draw();

    private:
        Window _window;
        Display* _pDisplay;
        int _width, _height;
        std::string _title;
    };
}