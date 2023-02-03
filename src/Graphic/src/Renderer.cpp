#include "../includes/Renderer.hpp"

#include "../includes/Shader.hpp"

#include <iostream>

namespace Graphic {
	Renderer::Renderer() {
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to initialize GLAD" << std::endl;
		}
	}

	int Renderer::init() {
		if (loadShaders() == RReturnCodes::R_LOAD_SHADERS_ERROR) return RReturnCodes::R_LOAD_SHADERS_ERROR;
		loadModel();

		return RReturnCodes::R_SUCCESS;
	}

	int Renderer::loadModel() {
		float vertices[] = {
			-0.5f, -0.5f,  1.0f,	1.0f, 0.0f, 0.0f,
			 0.0f,  0.5f,  1.0f,	0.0f, 1.0f, 0.0f,
			 0.5f, -0.5f,  1.0f,	0.0f, 0.0f, 1.0f
		};

		model = Model();
		model.create(vertices, sizeof(vertices), nullptr, 0, 3);
		model.setShader(shader);

		return RReturnCodes::R_SUCCESS;
	}

	int Renderer::loadShaders() {
		shader = createProgram("C:\\Users\\Никита\\Desktop\\NeuralEngine\\res\\ambientVS.glsl", "C:\\Users\\Никита\\Desktop\\NeuralEngine\\res\\ambientFS.glsl");
		if (shader == 0) return RReturnCodes::R_LOAD_SHADERS_ERROR;

		return RReturnCodes::R_SUCCESS;
	}

	void Renderer::render() {
		glClearColor(.0, .0, .0, .0);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shader);

		model.draw();
	}
}