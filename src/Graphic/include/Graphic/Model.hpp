#pragma once

#include <Graphic/Shader.hpp>
#include <System/ResourceManager.hpp>
#include <vector>

namespace Graphic {
    class Model {
    public:
        Model();
        ~Model() = default;

        void draw();

        void setShader(Shader __shader) { _shader = __shader; }
        void addTexture(System::STexture __texture);

    private:
        void _create();
        
        unsigned int _VBO, _VAO;
        Shader _shader;
        std::vector<System::STexture> _textures = std::vector<System::STexture>();
    };
}