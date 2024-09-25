#pragma once

#include <string>

struct LogType {
	LogType() {}
	LogType(std::string __color, std::string __text)
		: colorStr(__color), text(__text) {}

	std::string colorStr = "";
	std::string text = "";
};

struct Log {
	std::vector<std::string> lines = std::vector<std::string>();

	std::string title = "";
	std::string time = "";
	LogType type;

	bool isEnded = false;
};