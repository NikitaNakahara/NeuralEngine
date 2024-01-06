#pragma once

#include <Graphic/Camera.hpp>
#include <Graphic/Model.hpp>

#include <vector>
#include <string>

namespace Graphic {
    class Scene {
    public:
        Scene() = default;
        ~Scene() = default;

        void addCamera(Camera __camera, bool setActive = false);
        void addModel(Model __model);

        void draw();

    private:
        std::vector<Camera> _cameras = std::vector<Camera>();
        std::vector<Model> _models = std::vector<Model>();

        int _activeCameraIndex = 0;
    };
}