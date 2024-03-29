#include <glad/glad.h>

#include <Graphic/Renderer.hpp>


namespace Graphic {
    void Renderer::render() {
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        _scene.draw();
    }
}