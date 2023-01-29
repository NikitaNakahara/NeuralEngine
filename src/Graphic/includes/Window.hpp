#pragma once

#include <GLFW/glfw3.h>

#include <string>

enum WReturnCodes {
	W_SUCCESS,
	W_GLFW_INIT_ERROR,
	W_CREATE_WINDOW_ERROR,
	W_MAIN_LOOP_WINDOW_HANDLE_IS_NULLPTR_ERROR,
	W_MAIN_LOOP_ALREADY_STARTED_ERROR
};

namespace Graphic {
	class Window {
	public:
		Window(int width, int height, std::string title);
		Window() = default;
		~Window();

		int create(int width, int height, std::string title);
		int close();

		int startMainLoop();

	private:
		int mWidth = 0;
		int mHeight = 0;
		std::string mTitle = "";

		GLFWwindow* mWindow = nullptr;

		bool mMainLoopIsStarted = false;
	};
}