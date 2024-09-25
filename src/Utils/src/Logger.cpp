#include <Utils/Logger.hpp>

#include <Utils/Log.hpp>

#include <vector>
#include <malloc.h>
#include <stdio.h>


std::string getTimeString() {
	return "";
}


Log logStartBlock(std::string __title, LogType __type) {
	Log log = Log();

	log.title = __title;
	log.type = __type;
	log.time = getTimeString();

	return log;
}

void logEndBlock(Log* __log) {
	__log->isEnded = true;
}

void logAddLine(Log* __log, std::string __line) {
	__log->lines.push_back(__line);
}

void logAddLines(Log* __log, std::vector<std::string> __lines) {
	for (std::string line : __lines) {
		__log->lines.push_back(line);
	}
}

void logAddMultilineString(Log* __log, std::string __str) {
	std::vector<std::string> lines = std::vector<std::string>();
	std::string line = "";

	for (char c : __str) {
		if (c == '\n') {
			lines.push_back(line);
			line = "";
		}
		else {
			line += c;
		}
	}

	lines.push_back(line);

	logAddLines(__log, lines);
}

void logPrint(Log __log) {
	if (!__log.isEnded) return;

	if (__log.lines.size() == 1) {
		printf("%s [%s%s\033[0m] %s : %s\n", __log.time.c_str(), __log.type.colorStr.c_str(), __log.type.text.c_str(), __log.title.c_str(), __log.lines[0].c_str());
	}
	else {
		printf("%s [%s%s\033[0m] %s -- {\n", __log.time.c_str(), __log.type.colorStr.c_str(), __log.type.text.c_str(), __log.title.c_str());

		for (std::string line : __log.lines) {
			printf("\t%s\n", line.c_str());
		}

		printf("}\n");
	}
}