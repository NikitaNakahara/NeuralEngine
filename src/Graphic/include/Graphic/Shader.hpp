#pragma once

#include <string>

#include <glm/glm.hpp>

namespace Graphic {
    class Shader {
    public:
        Shader();
        ~Shader() = default;

        void use();

        unsigned int getProgram() const { return _program; }

        void operator=(const Shader& __shader) { this->_program = __shader.getProgram(); }

        void setTexture(unsigned int __texture,  int __index, std::string __name);
        void setMatrix(glm::mat4 __matrix, std::string __name);

    private:
        unsigned int _compile(std::string __data, unsigned int __type);
        void _linkProgram(unsigned int __vertex, unsigned int __fragment);

        const std::string _path = "../res/shaders/opengl/";

        unsigned int _program; 
    };
}