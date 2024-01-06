#pragma once

#include <glm/glm.hpp>

#include <GLFW/glfw3.h>


namespace Graphic {
    class Camera {
    public:
        Camera(GLFWwindow* __pWindow);
        ~Camera() = default;

        glm::mat4 getLookAt();

    private:
        void _move(int __key);
        void _rotate(double __x, double __y);

        glm::vec3 _cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
        glm::vec3 _cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 _cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
        bool _firstMouse = false;

        float _yaw   = -90.0f;
        float _pitch =   0.0f;
        float _lastX =  1920 / 2.0;
        float _lastY =  1080 / 2.0;
    };
}