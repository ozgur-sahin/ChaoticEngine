#pragma once

#define CH_LOG_LEVEL 0

#include <iostream>
#include <string>

enum class Log_Level : int
{
    Debug = 0,
    Info = 1,
    Warning = 2,
    Error = 3
};

class Logger
{
public:
    static void Debug(const std::string &strdebug);
    static void Info(const std::string &strmsg);
    static void Warning(const std::string &strwarn);
    static void Error(const std::string &strerr);
};

#define CH_LOG_DEBUG(...)                                             \
    if constexpr (CH_LOG_LEVEL <= static_cast<int>(Log_Level::Debug)) \
        Logger::Debug(__VA_ARGS__);

#define CH_LOG_INFO(...)                                             \
    if constexpr (CH_LOG_LEVEL <= static_cast<int>(Log_Level::Info)) \
        Logger::Info(__VA_ARGS__);

#define CH_LOG_WARNING(...)                                             \
    if constexpr (CH_LOG_LEVEL <= static_cast<int>(Log_Level::Warning)) \
        Logger::Warning(__VA_ARGS__);

#define CH_LOG_ERROR(...)                                             \
    if constexpr (CH_LOG_LEVEL <= static_cast<int>(Log_Level::Error)) \
        Logger::Error(__VA_ARGS__);
