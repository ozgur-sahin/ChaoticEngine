#pragma once

#define CH_DEBUG

#include <iostream>
#include <string>

enum class LogLevel
{
    Trace = 1,
    Debug = 2,
    Info = 3,
    Warning = 4,
    Error = 5,
    Fatal = 6,
    None = 7
};

class Logger
{
public:
    static void Trace(const std::string &strtrc);
    static void Info(const std::string &strmsg);
    static void Warning(const std::string &strwarn);
    static void Error(const std::string &strerr);
};
