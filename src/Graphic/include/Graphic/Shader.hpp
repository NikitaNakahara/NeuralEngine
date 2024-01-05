#pragma once

#include <string>

namespace Graphic {
    class Shader {
    public:
        Shader();
        ~Shader() = default;

        void use();

        unsigned int getProgram() const { return _program; }

        void operator=(const Shader& __shader) { this->_program = __shader.getProgram(); }

    private:
        unsigned int _compile(std::string __data, unsigned int __type);
        void _linkProgram(unsigned int __vertex, unsigned int __fragment);
        std::string _readFile(std::string __name);

        const std::string _path = "../res/shaders/opengl/";

        unsigned int _program; 
    };
}