#pragma once

#include "Model.hpp"

enum RReturnCodes {
	R_SUCCESS,
	R_LOAD_SHADERS_ERROR
};

namespace Graphic {
	class Renderer {
	public:
		Renderer();
		~Renderer() = default;

		int init();

		void render();

	private:
		int loadShaders();
		int loadModel();

		Model model;
		GLuint shader;
	};
}