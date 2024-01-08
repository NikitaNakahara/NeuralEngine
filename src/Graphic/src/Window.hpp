#pragma once

#include <string>

#include <X11/Xlib.h>

namespace Graphic {
    struct WndID;

    class MyWindow {
    public:
        MyWindow(int width, int height, std::string title, bool createFullscreen = false, WndID* __parentID = nullptr);
        ~MyWindow();

        void initGraphicContext();

        void draw();

        WndID* getWindowID() { return _id; }

    private:
        WndID* _id;
        int _width, _height;
        std::string _title;
    };
}