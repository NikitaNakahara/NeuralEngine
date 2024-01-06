#include <Graphic/Camera.hpp>

#include <glm/gtc/matrix_transform.hpp>

#include <System/Log.hpp>

namespace Graphic {
    int gKey = 0;
    glm::vec2 gCursorPos = glm::vec3(0.0f);

    Camera::Camera(GLFWwindow* __pWindow) {
        glfwSetKeyCallback(__pWindow, [](GLFWwindow* window, int key, int scancode, int action, int mode) {
            gKey = key;
        });

        glfwSetCursorPosCallback(__pWindow, [](GLFWwindow* window, double xpos, double ypos) {
            gCursorPos = glm::vec2(xpos, ypos);
        });


    }

    void Camera::_move(int __key) {
        GLfloat cameraSpeed = 0.05f;
        if(__key == GLFW_KEY_W)
            _cameraPos += cameraSpeed * _cameraFront;
        if(__key == GLFW_KEY_S)
            _cameraPos -= cameraSpeed * _cameraFront;
        if(__key == GLFW_KEY_A)
            _cameraPos -= glm::normalize(glm::cross(_cameraFront, _cameraUp)) * cameraSpeed;
        if(__key == GLFW_KEY_D)
            _cameraPos += glm::normalize(glm::cross(_cameraFront, _cameraUp)) * cameraSpeed;  
    }

    void Camera::_rotate(double __x, double __y) {
        if(_firstMouse) {
            _lastX = __x;
            _lastY = __y;
            _firstMouse = false;
        }
    
        GLfloat xoffset = __x - _lastX;
        GLfloat yoffset = _lastY - __y; 
        _lastX = __x;
        _lastY = __y;

        GLfloat sensitivity = 0.05;
        xoffset *= sensitivity;
        yoffset *= sensitivity;

        _yaw   += xoffset;
        _pitch += yoffset;

        if(_pitch > 89.0f)
            _pitch = 89.0f;
        if(_pitch < -89.0f)
            _pitch = -89.0f;

        glm::vec3 front;
        front.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
        front.y = sin(glm::radians(_pitch));
        front.z = sin(glm::radians(_yaw)) * cos(glm::radians(_pitch));
        _cameraFront = glm::normalize(front);
    }

    glm::mat4 Camera::getLookAt() {
        _move(gKey);
        gKey = 0;
        _rotate(gCursorPos.x, gCursorPos.y);

        return glm::lookAt(_cameraPos, _cameraPos + _cameraFront, _cameraUp);
    }
}