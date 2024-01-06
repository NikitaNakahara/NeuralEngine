#pragma once

#include <Graphic/Shader.hpp>
#include <Graphic/Camera.hpp>
#include <System/ResourceManager.hpp>
#include <vector>

#include <glm/glm.hpp>

namespace Graphic {
    class Model {
    public:
        Model();
        ~Model() = default;

        void draw();

        void setShader(Shader __shader) { _shader = __shader; }
        void addTexture(System::STexture __texture);

        void setTranslate(glm::vec3 __offset) { _translate = __offset; }
        void setRotation(glm::vec3 __offset, float __angle) { _rotate = __offset; _angle = __angle; }

        void setCameraPtr(Camera* __ptr) { _pCamera = __ptr; }

    private:
        void _create();
        
        Camera* _pCamera;
        unsigned int _VBO, _VAO;
        Shader _shader;
        std::vector<System::STexture> _textures = std::vector<System::STexture>();
        glm::vec3 _translate = glm::vec3(0.0f);
        glm::vec3 _rotate = glm::vec3(1.0f);
        float _angle = 0.0f;
    };
}