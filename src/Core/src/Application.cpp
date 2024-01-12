#include <Core/Application.hpp>

#include <Graphic/Graphic.hpp>
#include <Core/InputManager.hpp>

#include <System/Log.hpp>

namespace Core {
    void Application::launch() {
        Graphic::Wnd *window = Graphic::createOpenGLWindow(1920, 1080, "NeuralEngine");
        InputManager manager = InputManager(window->getWindowID());

        manager.setKeyPressCallback([](unsigned int key) {
            System::logDebug("App", std::to_string(key));
        });

        while (!manager.windowShouldClose()) {
            window->draw();
            manager.updateEvents();
        }
    }
}