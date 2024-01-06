#include <Graphic/Shader.hpp>

#include <System/Log.hpp>
#include <System/ResourceManager.hpp>

#include <fstream>
#include <vector>

#include <glad/glad.h>

#include <glm/gtc/type_ptr.hpp>

namespace Graphic {
    Shader::Shader() {
        unsigned int vertex, fragment;
        
        System::SShader sshader = System::ResourceManager::loadShader("opengl/ambient");
        vertex = _compile(sshader.vertex, GL_VERTEX_SHADER);
        fragment = _compile(sshader.fragment, GL_FRAGMENT_SHADER);

        _linkProgram(vertex, fragment);
    }

    unsigned int Shader::_compile(std::string __data, unsigned int __type) {
        unsigned int shader = glCreateShader(__type);

        const char* data = __data.c_str();
        glShaderSource(shader, 1, &data, NULL);
        glCompileShader(shader);

        int success;
        char infoLog[512];
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 512, NULL, infoLog);
            System::logCritical("Shader", "compile error: " + std::string(infoLog));
        }

        return shader;
    }

    void Shader::_linkProgram(unsigned int __vertex, unsigned int __fragment) {
        _program = glCreateProgram();

        glAttachShader(_program, __vertex);
        glAttachShader(_program, __fragment);
        glLinkProgram(_program);

        int success;
        char infoLog[512];
        glGetProgramiv(_program, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(_program, 512, NULL, infoLog);
            System::logCritical("Shader", "link error: " + std::string(infoLog));
        }

        glDeleteShader(__vertex);
        glDeleteShader(__fragment);
    }

    void Shader::use() {
        glUseProgram(_program);
    }

    void Shader::setTexture(unsigned int __texture, int __index, std::string __name)  {
        glActiveTexture(GL_TEXTURE0 + __index);
        glBindTexture(GL_TEXTURE_2D, __texture);
        glUniform1i(glGetUniformLocation(_program, __name.c_str()), __index);
    }

    void Shader::setMatrix(glm::mat4 __matrix, std::string __name) {
        glUniformMatrix4fv(glGetUniformLocation(_program, __name.c_str()), 1, GL_FALSE, glm::value_ptr(__matrix));
    }
}