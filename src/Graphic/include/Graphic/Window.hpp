#pragma once

#include <string>
#include <GLFW/glfw3.h>

class Window {
public:
    Window(int width, int height, std::string title);
    ~Window() = default;

private:
    void mainLoop();

    GLFWwindow* _pWindow;
    int _width, _height;
    std::string _title;
};