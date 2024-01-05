#include <glad/glad.h>

#include <Graphic/Window.hpp>
#include <Graphic/Shader.hpp>
#include <Graphic/Model.hpp>
#include <System/Log.hpp>

namespace Graphic {
    Window::Window(int __width, int __height, std::string __title, bool __createFullscreen)
        : _width(__width), _height(__height), _title(__title) {
        System::logInfo("Window", "start creating window");
        if (!glfwInit()) {
            System::logCritical("glfw error", "can't init GLFW");
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

        GLFWmonitor* monitor = nullptr;
        if (__createFullscreen) monitor = glfwGetPrimaryMonitor();
        _pWindow = glfwCreateWindow(_width, _height, _title.c_str(), monitor, nullptr);
        if (_pWindow == nullptr) {
            System::logCritical("glfw error", "can't create window");
            return;
        }

        System::logInfo("Window", "window creating success");

        glfwFocusWindow(_pWindow);
        glfwMakeContextCurrent(_pWindow);

        int gladInitResult = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        switch (gladInitResult)
        {
        case -1:
            System::logCritical("Renderer", "glGetString is NULL");
            break;
            
        case -2:
            System::logCritical("Renderer", "gl version is NULL");
            break;

        case -3:
            System::logCritical("Renderer", "GL extensions not found");
            break;
        
        default:
            System::logDebug("Renderer", "GL loader was initialized");
        }

        glViewport(0, 0, __width, __height);

        Shader shader = Shader();
        Model model = Model();
        model.setShader(shader);
        model.addTexture(System::ResourceManager::loadTexture("container.jpg"));
        
        _renderer = Renderer();
        _renderer.addModel(model);

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