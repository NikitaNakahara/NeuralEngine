#include <System/ResourceManager.hpp>

#include <fstream>
#include <vector>
#include <map>
#include <cstring>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <System/Log.hpp>

namespace System::ResourceManager {
    std::map<std::string, SShader> _shaders = std::map<std::string, SShader>();
    std::map<std::string, STexture> _textures = std::map<std::string, STexture>();

    STexture loadTexture(std::string __name) {
        STexture texture = STexture();
        texture.name = __name;

        unsigned char* image = stbi_load(("../res/textures/" + __name).c_str(), &texture.width, &texture.height, &texture.comp, STBI_rgb);
        texture.img = image;
        texture.format = FORMAT_RGB;
        texture.name = __name.substr(0, __name.length() - 4);

        return texture;
    }

    SShader loadShader(std::string __name) {
        std::string path = "../res/shaders/" + __name;

        std::ifstream vStream = std::ifstream(path + ".vs");
        std::ifstream fStream = std::ifstream(path + ".fs");

        if (!vStream) {
            System::logCritical("Shader error", "can't load file for path: " + path + ".vs");
        }

        if (!fStream) {
          System::logCritical("Shader error", "can't load file for path: " + path + ".fs");
        }


        std::vector<std::string> vLines;
        std::vector<std::string> fLines;

        std::string vShaderLine = "";
        while (getline(vStream, vShaderLine)) {
            vLines.push_back(vShaderLine);
        }
        vStream.clear();

        std::string fShaderLine = "";
        while (getline(fStream, fShaderLine)) {
            fLines.push_back(fShaderLine);
        }
        fStream.clear();

        std::string vertex = "";
        for (std::string line : vLines) {
            vertex += line + '\n';
        }

        std::string fragment = "";
        for (std::string line : fLines) {
            fragment += line + '\n';
        }

        SShader shader = SShader();
        shader.name = __name;
        shader.vertex = vertex;
        shader.fragment = fragment;

        return shader;
    }
}