#pragma once

#include <string>
#include <GLFW/glfw3.h>

#include <Graphic/Renderer.hpp>

namespace Graphic {
    class Window {
    public:
        Window(int __width, int __height, std::string __title, bool __createFullscreen);
        ~Window() = default;

    private:
        void _mainLoop();

        GLFWwindow* _pWindow;
        int _width, _height;
        std::string _title;
        Renderer _renderer;
    };
}