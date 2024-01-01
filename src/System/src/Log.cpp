#include <System/Log.hpp>

#include <stdio.h>
#include <ctime>

std::string getTime() {
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    
    std::string day = std::to_string(now->tm_mday);
    if (day.length() == 1) day = '0' + day;
    std::string month = std::to_string(now->tm_mon + 1);
    if (month.length() == 1) month = '0' + month;
    std::string year = std::to_string(now->tm_year + 1900);

    std::string sec = std::to_string(now->tm_sec);
    if (sec.length() == 1) sec = '0' + sec;
    std::string min = std::to_string(now->tm_min);
    if (min.length() == 1) min = '0' + min;
    std::string hour = std::to_string(now->tm_hour);
    if (hour.length() == 1) hour = '0' + hour;

    return day + '.' + month + '.' + year + ' ' + hour + ':' + min + ':' + sec;
}

namespace System {
    void logDebug(std::string title, std::string text) {
        printf("%s [\033[0;36mDEBUG\033[0;0m] %s : %s\n", getTime().c_str(), title.c_str(), text.c_str());
    }

    void logInfo(std::string title, std::string text) {
        printf("%s [\033[0;32mINFO\033[0;0m] %s : %s\n", getTime().c_str(), title.c_str(), text.c_str());
    }

    void logWarning(std::string title, std::string text) {
        printf("%s [\033[0;33mWARNING\033[0;0m] %s : %s\n", getTime().c_str(), title.c_str(), text.c_str());
    }

    void logError(std::string title, std::string text) {
        printf("%s [\033[0;31mERROR\033[0;0m] %s : %s\n", getTime().c_str(), title.c_str(), text.c_str());
    }

    void logCritical(std::string title, std::string text, bool stop, int status) {
        printf("%s [\033[0;41mCRITICAL\033[0;0m] %s : %s\n", getTime().c_str(), title.c_str(), text.c_str());

        if (stop) {
            exit(status);
        }
    }
}