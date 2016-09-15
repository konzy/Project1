//
// Created by Owner on 9/9/2016.
//

#ifndef PROJECT1_LOGGER_H
#define PROJECT1_LOGGER_H

#include <string>
#include <iostream>

using namespace std;

class Logger {

public:

    void log(const string);
    static Logger* getLogger();

private:
    Logger();
    Logger(const Logger&);
    static Logger *logger;
};


#endif //PROJECT1_LOGGER_H
