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

constexpr int operator+(Log_Level l)
{
    return static_cast<int>(l);
}

class Logger
{
public:
    std::ostream *outstream{&std::cout};
    std::ostream *errstream{&std::cerr};

    Logger();
    Logger(std::ostream *, std::ostream *);
    ~Logger();

    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

    Logger(Logger &&);
    Logger &operator=(Logger &&);

    void Debug(const std::string &);
    void Info(const std::string &);
    void Warning(const std::string &);
    void Error(const std::string &);
};

extern Logger logger;

#define CH_LOG_DEBUG(...)                            \
    if constexpr (CH_LOG_LEVEL <= +Log_Level::Debug) \
        logger.Debug(__VA_ARGS__);

#define CH_LOG_INFO(...)                            \
    if constexpr (CH_LOG_LEVEL <= +Log_Level::Info) \
        logger.Info(__VA_ARGS__);

#define CH_LOG_WARNING(...)                            \
    if constexpr (CH_LOG_LEVEL <= +Log_Level::Warning) \
        logger.Warning(__VA_ARGS__);

#define CH_LOG_ERROR(...)                            \
    if constexpr (CH_LOG_LEVEL <= +Log_Level::Error) \
        logger.Error(__VA_ARGS__);
