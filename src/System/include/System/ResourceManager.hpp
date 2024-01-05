#pragma once

#include <string>

#define FORMAT_RGBA 1;
#define FORMAT_RGB 2;


namespace System {
    struct STexture {
        int width, height, comp;
        unsigned char* img;
        std::string name;
        int format;
        unsigned int texture;

        void freeData() {
            free(img);
        }
    };

    struct SShader {
        std::string vertex, fragment, name;
    };

    namespace ResourceManager {
        STexture loadTexture(std::string __name);
        SShader loadShader(std::string __name);        
    };
}