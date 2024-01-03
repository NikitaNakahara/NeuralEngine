#pragma once

#include <vector>
#include <Graphic/Model.hpp>
#include <Graphic/Shader.hpp>

namespace Graphic {
    class Renderer {
    public:
        Renderer();
        ~Renderer() = default;

        void render();

        void addModel(Model __model) { _models.push_back(__model); }

    private:
        Shader _shader;
        std::vector<Model> _models = std::vector<Model>();
        float _backgroundColor[4] = { 0.0, 0.0, 1.0, 1.0 };
    };
}
