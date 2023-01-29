#include "Log.hpp"

#include <iostream>

namespace Core {
	namespace log {
		void info(std::string text) {
			std::cout << "[CORE] " << text << std::endl;
		}
	}
}