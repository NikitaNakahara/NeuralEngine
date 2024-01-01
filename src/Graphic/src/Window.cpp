#include <glad/glad.h>

#include <Graphic/Window.hpp>

#include <iostream>

Window::Window(int width, int height, std::string title)
    : _width(width), _height(height), _title(title) {
    if (!glfwInit()) {
        std::cout << "can't init glfw\n";
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

    _pWindow = glfwCreateWindow(_width, _height, _title.c_str(), nullptr, nullptr);
    if (_pWindow == nullptr) return;

    glfwMakeContextCurrent(_pWindow);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    mainLoop();
}

void Window::mainLoop() {
    while(!glfwWindowShouldClose(_pWindow)) {
        glClearColor(0.0, 0.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(_pWindow);
        glfwPollEvents();
    }
}