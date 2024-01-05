#include <Graphic/Shader.hpp>

#include <System/Log.hpp>

#include <fstream>
#include <vector>

#include <glad/glad.h>

namespace Graphic {
    Shader::Shader() {
        unsigned int vertex, fragment;
        
        vertex = _compile(_readFile("vertex.glsl"), GL_VERTEX_SHADER);
        fragment = _compile(_readFile("fragment.glsl"), GL_FRAGMENT_SHADER);

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

        System::logInfo("Shader", "linked: " + std::to_string(_program));
    }

    std::string Shader::_readFile(std::string __name) {
        std::string fileType;

        std::string path = _path + __name;

        std::ifstream stream = std::ifstream(path);

        if (!stream) {
            System::logCritical("Shader error", "can't load file for path: " + path);
        }

        std::vector<std::string> lines;

        std::string shaderLine = "";
        while (getline(stream, shaderLine)) {
            lines.push_back(shaderLine);
        }

        stream.clear();

        std::string result = "";
        for (std::string line : lines) {
            result += line + '\n';
        }

        return result;
    }

    void Shader::use() {
        System::logInfo("Shader", "using: " + std::to_string(_program));
        glUseProgram(_program);
    }
}