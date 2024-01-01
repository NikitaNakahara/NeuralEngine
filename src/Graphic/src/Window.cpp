#include <glad/glad.h>

#include <Graphic/Window.hpp>
#include <System/Log.hpp>

namespace Graphic {
    Window::Window(int width, int height, std::string title, bool createFullscreen)
        : _width(width), _height(height), _title(title) {
        System::logInfo("Window", "start creating window");
        if (!glfwInit()) {
            System::logCritical("glfw error", "can't init GLFW");
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

        GLFWmonitor* monitor = nullptr;
        if (createFullscreen) monitor = glfwGetPrimaryMonitor();
        _pWindow = glfwCreateWindow(_width, _height, _title.c_str(), monitor, nullptr);
        if (_pWindow == nullptr) {
            System::logCritical("glfw error", "can't create window");
            return;
        }

        System::logInfo("Window", "window creating success");

        glfwMakeContextCurrent(_pWindow);

        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

        mainLoop();
    }

    void Window::mainLoop() {
        while(!glfwWindowShouldClose(_pWindow)) {
            if (glfwGetKey(_pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                glfwSetWindowShouldClose(_pWindow, true);
            }

            glClearColor(0.0, 0.0, 1.0, 1.0);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(_pWindow);
            glfwPollEvents();
        }
    }
}