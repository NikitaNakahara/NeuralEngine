#include <Core/Application.hpp>

#include <NeuralGL/ngl.hpp>
#include <Core/InputManager.hpp>

#include <System/Log.hpp>

#include <unistd.h>

namespace Core {
    void Application::launch() {
        ngl::NGLWindow *window = ngl::createWindow(1920, 1080, "NeuralEngine");
        if (window == nullptr) System::logError("NGL", ngl::getLastError());
        ngl::initOpenGLContext(window);
        
        sleep(5);

        ngl::clearWindow(window);
    }
}