#pragma once

#include <string>

namespace System {
    void logInfo(std::string title, std::string text);
    void logError(std::string title, std::string text);
    void logCritical(std::string title, std::string text);
}