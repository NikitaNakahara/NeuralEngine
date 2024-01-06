#include <glad/glad.h>

#include <Graphic/Model.hpp>

#include <GLFW/glfw3.h>
#include <System/Log.hpp>

#include <glm/gtc/matrix_transform.hpp>

namespace Graphic {
    Model::Model() {
        _create();
    }

    void Model::draw() {
        for (int i = 0; i < _textures.size(); i++) {
            _shader.setTexture(_textures[i].texture, i, _textures[i].name);
        }

        _shader.use();

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, _translate);
        model = glm::rotate(model, glm::radians(_angle), _rotate);

        glm::mat4 view = _pCamera->getLookAt();

        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(45.0f, 1920.0f / 1080.0f, 0.1f, 100.0f);

        _shader.setMatrix(model, "model");
        _shader.setMatrix(view, "view");
        _shader.setMatrix(projection, "projection");

        glBindVertexArray(_VAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);
    }

    void Model::addTexture(System::STexture __texture) {
        glGenTextures(1, &__texture.texture);
        glBindTexture(GL_TEXTURE_2D, __texture.texture);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, __texture.width, __texture.height, 0, GL_RGB, GL_UNSIGNED_BYTE, __texture.img);
        glGenerateMipmap(GL_TEXTURE_2D);

        __texture.freeData();

        glBindTexture(GL_TEXTURE_2D, 0);

        _textures.push_back(__texture);
    }

    void Model::_create() {
        float vertices[] = {
           -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
           -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
           -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

           -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
           -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
           -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

           -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
           -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
           -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
           -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
           -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
           -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

           -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
           -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
           -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

           -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
           -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
           -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
        };

        glGenVertexArrays(1, &_VAO);
        glGenBuffers(1, &_VBO);
        
        glBindVertexArray(_VAO);

        glBindBuffer(GL_ARRAY_BUFFER, _VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindVertexArray(0);
    }
}