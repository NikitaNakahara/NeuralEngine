#include <glad/glad.h>

#include <Graphic/Window.hpp>
#include <System/Log.hpp>

namespace Graphic {
    Window::Window(int __width, int __height, std::string __title, bool __createFullscreen)
        : _width(__width), _height(__height), _title(__title) {
        if (!glfwInit()) {
            System::logCritical("glfw error", "can't init GLFW");
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        GLFWmonitor* monitor = nullptr;
        if (__createFullscreen) monitor = glfwGetPrimaryMonitor();
        _pWindow = glfwCreateWindow(_width, _height, _title.c_str(), monitor, nullptr);
        if (_pWindow == nullptr) {
            System::logCritical("glfw error", "can't create window");
            return;
        }

        glfwFocusWindow(_pWindow);

        glfwMakeContextCurrent(_pWindow);

        _renderer = Renderer();
        _renderer.addModel(Model(Shader()));

        _mainLoop();
    }

    void Window::_mainLoop() {
        while(!glfwWindowShouldClose(_pWindow)) {
            if (glfwGetKey(_pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                glfwSetWindowShouldClose(_pWindow, true);
            }

            _renderer.render();

            glfwSwapBuffers(_pWindow);
            glfwPollEvents();
        }
    }
}