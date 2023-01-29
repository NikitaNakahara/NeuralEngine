#include "../includes/Window.hpp"


namespace Graphic {
	Window::Window(int width, int height, std::string title)
		: mWidth(width), mHeight(height), mTitle(title)
	{
		create(width, height, title);
	}

	Window::~Window() {
		close();
	}

	int Window::create(int width, int height, std::string title) {
		if (glfwInit() != GLFW_TRUE) {
			return WReturnCodes::W_GLFW_INIT_ERROR;
		}

		if (!(mWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr))) {
			glfwTerminate();

			return WReturnCodes::W_CREATE_WINDOW_ERROR;
		}

		glfwMakeContextCurrent(mWindow);

		return WReturnCodes::W_SUCCESS;
	}

	int Window::startMainLoop() {
		if (mWindow == nullptr) {
			return WReturnCodes::W_MAIN_LOOP_WINDOW_HANDLE_IS_NULLPTR_ERROR;
		}

		if (mMainLoopIsStarted) {
			return WReturnCodes::W_MAIN_LOOP_ALSO_STARTED_ERROR;
		}

		while (!glfwWindowShouldClose(mWindow)) {
			glfwSwapBuffers(mWindow);
			glfwPollEvents();
		}

		return WReturnCodes::W_SUCCESS;
	}

	int Window::close() {
		glfwSetWindowShouldClose(mWindow, true);
		glfwTerminate();

		return WReturnCodes::W_SUCCESS;
	}
}