#include "logger.h"

Logger logger;

Logger::Logger()
{
    os = &std::cout;
    errstream = &std::cerr;
}

void Logger::Debug(const std::string &strdebug)
{
    *os << "LOGGER[DEBUG]: " + strdebug + "\n";
}

void Logger::Info(const std::string &strmsg)
{
    *os << "LOGGER[INFO]: " << strmsg << "\n";
}

void Logger::Warning(const std::string &strwarn)
{
    *os << "LOGGER[WARNING]: " << strwarn << "\n";
}

void Logger::Error(const std::string &strerr)
{
    *errstream << "LOGGER[ERROR]: " << strerr << "\n";
}