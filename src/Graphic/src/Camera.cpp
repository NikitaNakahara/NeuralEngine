#include <Graphic/Camera.hpp>

#include <glm/gtc/matrix_transform.hpp>

#include <GLFW/glfw3.h>

namespace Graphic {
    void Camera::move(int __key) {
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

    void Camera::rotate(double __x, double __y) {
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
        return glm::lookAt(_cameraPos, _cameraUp + _cameraFront, _cameraUp);
    }
}