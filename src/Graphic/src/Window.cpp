#include <glad/glad.h>

#include <Graphic/Window.hpp>
#include <Graphic/Shader.hpp>
#include <Graphic/Model.hpp>
#include <Graphic/Camera.hpp>
#include <System/Log.hpp>

namespace Graphic {
    Camera camera = Camera();

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
        glfwSetInputMode(_pWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

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
        glEnable(GL_DEPTH_TEST);

        glfwSetKeyCallback(_pWindow, [](GLFWwindow* window, int key, int scancode, int action, int mode) {
            camera.move(key);
        });

        glfwSetCursorPosCallback(_pWindow, [](GLFWwindow* window, double xpos, double ypos) {
            camera.rotate(xpos, ypos);
        });

        Shader shader = Shader();

        glm::vec3 cubePositions[] = {
            glm::vec3( 0.0f,  0.0f,  0.0f), 
            glm::vec3( 2.0f,  5.0f, -15.0f), 
            glm::vec3(-1.5f, -2.2f, -2.5f),  
            glm::vec3(-3.8f, -2.0f, -12.3f),  
            glm::vec3( 2.4f, -0.4f, -3.5f),  
            glm::vec3(-1.7f,  3.0f, -7.5f),  
            glm::vec3( 1.3f, -2.0f, -2.5f),  
            glm::vec3( 1.5f,  2.0f, -2.5f), 
            glm::vec3( 1.5f,  0.2f, -1.5f), 
            glm::vec3(-1.3f,  1.0f, -1.5f)  
        };
       
        _renderer = Renderer();

        for (int i = 0; i < sizeof(cubePositions) / sizeof(glm::vec3); i++) {
            Model model = Model();
            model.setCameraPtr(&camera);
            model.setShader(shader);
            model.addTexture(System::ResourceManager::loadTexture("container.jpg"));
            model.setTranslate(cubePositions[i]);
            model.setRotation(glm::vec3(1.0f, 0.3f, 0.5f), 20.0f * i);
            _renderer.addModel(model);
        }

        _mainLoop();
    }

    void Window::_mainLoop() {
        while(!glfwWindowShouldClose(_pWindow)) {
            glfwPollEvents();

            if (glfwGetKey(_pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                glfwSetWindowShouldClose(_pWindow, true);
            }

            _renderer.render();

            glfwSwapBuffers(_pWindow);
        }
    }
}