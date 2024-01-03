#include <Graphic/Renderer.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <System/Log.hpp>

namespace Graphic {
    Renderer::Renderer() {
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

        _shader = Shader(GLSL);
    }

    void Renderer::render() {
        glClearColor(_backgroundColor[0], _backgroundColor[1], _backgroundColor[2], _backgroundColor[3]);
        glClear(GL_COLOR_BUFFER_BIT);

        _shader.use();
        for (Model model : _models) {
            model.draw();
        }
    }
}