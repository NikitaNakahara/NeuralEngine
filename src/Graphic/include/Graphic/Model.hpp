#pragma once

#include <Graphic/Shader.hpp>

namespace Graphic {
    class Model {
    public:
        Model(Shader __shader);
        ~Model() = default;

        void draw();

        void setShader(Shader __shader) { _shader = __shader; }

    private:
        void _create();

        unsigned int _VBO, _VAO;
        Shader _shader;
    };
}