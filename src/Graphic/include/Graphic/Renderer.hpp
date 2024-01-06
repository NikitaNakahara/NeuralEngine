#pragma once

#include <Graphic/Scene.hpp>

#include <vector>

namespace Graphic {
    class Renderer {
    public:
        Renderer() = default;
        ~Renderer() = default;

        void render();

        void setScene(Scene __scene) { _scene = __scene; }

    private:
        Scene _scene;
    };
}