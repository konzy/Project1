//
// Created by Owner on 9/9/2016.
//

#include "Logger.h"

using namespace std;

Logger* Logger::logger = NULL;

Logger::Logger(){}

Logger* Logger::getLogger(){
    if (logger == NULL) {
        logger = new Logger();
    }
    return logger;
}

void Logger::log(const string s) {
    cout << s;
}