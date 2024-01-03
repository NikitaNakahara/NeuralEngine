#pragma once

#include <string>

#define GLSL 1

namespace Graphic {
    class Shader {
    public:
        Shader() = default;
        Shader(int __language);
        ~Shader() = default;

        void use();

    private:
        int _language;
        int _compile(std::string __data, int __mode);
        void _createProgram(int __vertex, int __fragment);
        std::string _loadFile(std::string __name);

        int _program = 0;
        std::string _path = "../res/shaders/opengl/";
    };
}