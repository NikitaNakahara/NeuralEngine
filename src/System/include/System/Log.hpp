#pragma once

#include <string>

namespace System {
    void logDebug(std::string title, std::string text);
    void logInfo(std::string title, std::string text);
    void logWarning(std::string title, std::string text);
    void logError(std::string title, std::string text);
    void logCritical(std::string title, std::string text, bool stop = true, int status = -1);
}