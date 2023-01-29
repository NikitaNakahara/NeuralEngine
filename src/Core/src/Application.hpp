#pragma once

#define APPLICATION_SUCCESS 0
#define CANT_CREATE_WINDOW	1

enum AReturnCodes {
	A_SUCCESS,
	A_CREATE_WINDOW_ERROR,
	A_WINDOW_MAIN_LOOP_ERROR
};

namespace Core {
	class Application {
	public:
		Application() = default;
		~Application() = default;

		int init();

	private:
		int createWindow();
	};
}