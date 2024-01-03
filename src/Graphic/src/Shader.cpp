#include <Graphic/Shader.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <vector>
#include <stdlib.h>

#include <System/Log.hpp>

namespace Graphic {
    Shader::Shader(int __language) : _language(__language) {

        int vertex, fragment;
        vertex = _compile(_loadFile("vertex"), GL_VERTEX_SHADER);
        fragment = _compile(_loadFile("vertex"), GL_FRAGMENT_SHADER);

        _createProgram(vertex, fragment);
    }

    void Shader::use() {
        if (_language == GLSL) glUseProgram(_program);
    }

    int Shader::_compile(std::string __data, int __mode) {
        if (_language == GLSL) {
            unsigned int shader = glCreateShader(__mode);

            const char* data = __data.c_str();
            glShaderSource(shader, 1, &data, NULL);
            glCompileShader(shader);

            GLint success;
            GLchar infoLog[512];
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

            if(!success) {
                glGetShaderInfoLog(shader, 512, NULL, infoLog);
                System::logCritical("Shader", "failed compile shader: " + std::string(infoLog));
            }

            return shader;
        }

        return 0;
    }

    void Shader::_createProgram(int __vertex, int __fragment) {
        if (_language == GLSL) {
            _program = glCreateProgram();

            glAttachShader(_program, __vertex);
            glAttachShader(_program, __fragment);
            glLinkProgram(_program);

            GLint success;
            GLchar infoLog[512];
            glGetProgramiv(_program, GL_LINK_STATUS, &success);
            if (!success) {
                glGetProgramInfoLog(_program, 512, NULL, infoLog);
                System::logCritical("Shader", "failed link shader program: " + std::string(infoLog));
            }

            glDeleteShader(__vertex);
            glDeleteShader(__fragment);
        }
    }

    std::string Shader::_loadFile(std::string __name) {
        std::string fileType;
        if (_language == GLSL) fileType = ".glsl";

        std::string path = _path + __name + fileType;

        std::ifstream stream = std::ifstream(path);

        char* realPath = realpath(path.c_str(), nullptr);
        if (realPath == nullptr) System::logError("Shader error", "file for path \"" + path + "\" isn't exists");
        if (!stream) {
            if (realPath == nullptr) System::logCritical("Shader error", "can't load file for path: " + path);
            else System::logCritical("Shader error", "can't load file for path: " + std::string(realPath));
        }

        std::vector<std::string> lines;

        std::string shaderLine = "";
        while (getline(stream, shaderLine)) {
            lines.push_back(shaderLine);
        }

        std::string result = "";
        for (std::string line : lines) {
            result += line + '\n';
        }

        return result;
    }
}