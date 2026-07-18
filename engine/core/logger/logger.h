#pragma once

#include <iostream>
#include <string>

class Logger
{
public:
    static void Info(const std::string &strmsg);
    static void Warning(const std::string &strwarn);
    static void Error(const std::string &strerr);
};
