#include <Graphic/Model.hpp>

#include <glad/glad.h>
#include <System/Log.hpp>

namespace Graphic {
    Model::Model() {
        _create();
    }

    void Model::draw() {
        _shader.use();

        for (int i = 0; i < _textures.size(); i++) {
            _shader.addTexture(_textures[i].texture, i, _textures[i].name);
        }
        glBindVertexArray(_VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
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
//          Позиции             Цвета               Текстурные координаты
            0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // Верхний правый
            0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // Нижний правый
           -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // Нижний левый

           -0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,   0.0f, 1.0f,   // Верхний левый
            0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // Верхний правый
           -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // Нижний левый
        };  

        glGenVertexArrays(1, &_VAO);
        glGenBuffers(1, &_VBO);
        
        glBindVertexArray(_VAO);

        glBindBuffer(GL_ARRAY_BUFFER, _VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
        glEnableVertexAttribArray(2);

        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindVertexArray(0);
    }
}