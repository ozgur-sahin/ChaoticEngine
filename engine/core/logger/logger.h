#pragma once

#define CH_LOG_LEVEL 3

#include <iostream>
#include <string>

enum class Log_Level
{
    Debug = 0,
    Info = 1,
    Warning = 2,
    Error = 3
};

class Logger
{
public:
    static void Info(const std::string &strmsg);
    static void Warning(const std::string &strwarn);
    static void Error(const std::string &strerr);
};
