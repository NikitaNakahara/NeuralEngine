#pragma once

#include <string>
#include <vector>

#include <Utils/Log.hpp>

#define DEBUG	LogType("\033[1;34m", "DEBUG")
#define INFO	LogType("\033[1;32m", "INFO")
#define WARN	LogType("\033[1;33m", "WARN")
#define ERROR	LogType("\033[1;31m", "ERROR")
#define CRIT	LogType("\033[1;41m", "CRITICAL")

Log logStartBlock(std::string __title, LogType __type);
void logEndBlock(Log* __log);
void logAddLine(Log* __log, std::string __line);
void logAddLines(Log* __log, std::vector<std::string> __lines);
void logAddMultilineString(Log* __log, std::string __str);
void logPrint(Log __log);