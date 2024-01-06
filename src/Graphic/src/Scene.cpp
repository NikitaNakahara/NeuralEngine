#include <Graphic/Scene.hpp>


namespace Graphic {
    void Scene::addModel(Model __model) {
        __model.setCameraPtr(&_cameras[_activeCameraIndex]);
        _models.push_back(__model);
    }

    void Scene::addCamera(Camera __camera, bool setActive) {
        _cameras.push_back(__camera);
        if (setActive) _activeCameraIndex = _cameras.size() - 1;
    }

    void Scene::draw() {
        for (Model model : _models) {
            model.draw();
        }
    }
}