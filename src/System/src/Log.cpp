#include <System/Log.hpp>

#include <stdio.h>

namespace System {
    void logInfo(std::string title, std::string text) {
        printf("Log [\033[0;32mINFO\033[0;0m] %s : %s\n", title.c_str(), text.c_str());
    }

    void logError(std::string title, std::string text) {
        printf("Log [\033[0;31mERROR\033[0;0m] %s : %s\n", title.c_str(), text.c_str());
    }

    void logCritical(std::string title, std::string text) {
        printf("Log [\033[41;0mCRITICAL\033[0;0m] %s : %s\n", title.c_str(), text.c_str());
    }
}