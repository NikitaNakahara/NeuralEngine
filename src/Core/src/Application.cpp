#include "Application.hpp"

#include "../../Graphic/includes/Window.hpp"
#include "Log.hpp"

namespace Core {
	int Application::init() {
		return createWindow();
	}

	int Application::createWindow() {
		Graphic::Window window = Graphic::Window();

		if (window.create(1080, 720, "Neural Engine") != WReturnCodes::W_SUCCESS) {
			log::info("Application: create window error");
			return AReturnCodes::A_CREATE_WINDOW_ERROR;
		}

		if (window.startMainLoop() != WReturnCodes::W_SUCCESS) {
			log::info("Application: window main loop error");
			return AReturnCodes::A_WINDOW_MAIN_LOOP_ERROR;
		}

		return A_SUCCESS;
	}
}