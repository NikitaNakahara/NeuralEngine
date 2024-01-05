#pragma once

#include <Graphic/Model.hpp>

#include <vector>

namespace Graphic {
    class Renderer {
    public:
        Renderer() = default;
        ~Renderer() = default;

        void render();

        void addModel(Model __model) { _models.push_back(__model); }

    private:
        std::vector<Model> _models = std::vector<Model>();
    };
}