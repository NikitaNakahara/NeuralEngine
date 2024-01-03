#include <Graphic/Model.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <System/Log.hpp>

namespace Graphic {
    Model::Model(Shader __shader) : _shader(__shader) {
        _create();
    }

    void Model::draw() {
        _shader.use();
        glBindVertexArray(_VAO); 
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0); 
    }

    void Model::_create() {
        GLfloat vertices[] = {
           -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
        };

        glGenBuffers(1, &_VBO);
        glGenVertexArrays(1, &_VAO);

        glBindVertexArray(_VAO);
        
        glBindBuffer(GL_ARRAY_BUFFER, _VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);
        
        glBindVertexArray(0);

        System::logDebug("Model", "created with VBO: " + std::to_string(_VBO) + " & VAO: " + std::to_string(_VAO));
    }
}