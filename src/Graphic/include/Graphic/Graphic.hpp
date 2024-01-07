#include "../../src/Window.hpp"


namespace Graphic {
    MyWindow createWindow(int __width, int __height, std::string __title) {
        return MyWindow(__width, __height, __title);
    }
}