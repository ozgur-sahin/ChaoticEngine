#include "logger.h"

void Logger::Debug(const std::string &strdebug)
{
    std::cout << "LOGGER[DEBUG]: " + strdebug + "\n";
}

void Logger::Info(const std::string &strmsg)
{
    std::cout << "LOGGER[INFO]: " << strmsg << "\n";
}

void Logger::Warning(const std::string &strwarn)
{
    std::cout << "LOGGER[WARNING]: " << strwarn << "\n";
}

void Logger::Error(const std::string &strerr)
{
    std::cerr << "LOGGER[ERROR]: " << strerr << "\n";
}