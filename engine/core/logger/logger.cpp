#include "logger.h"
#include <fstream>

// std::ofstream outputstream{}

Logger logger{};

Logger::Logger()
{
}

Logger::Logger(std::ostream *ostrm, std::ostream *estrm) : outstream{ostrm},
                                                           errstream{estrm}
{
    if (ostrm == nullptr)
    {
        std::cout << "Invalid output stream. Defaulting to standard output.\n";
        outstream = &std::cout;
    }
    if (estrm == nullptr)
    {
        std::cout << "Invalid error output stream. Defaulting to standard error output.\n";
        errstream = &std::cerr;
    }
}

Logger::~Logger()
{
}

Logger::Logger(Logger &&old_logger)
{
    outstream = old_logger.outstream;
    errstream = old_logger.errstream;
    old_logger.outstream = &std::cout;
    old_logger.errstream = &std::cerr;
}

Logger &Logger::operator=(Logger &&old_logger)
{
    if (this != &old_logger)
    {
        outstream = old_logger.outstream;
        errstream = old_logger.errstream;
        old_logger.outstream = &std::cout;
        old_logger.errstream = &std::cerr;
    }
    return *this;
}

void Logger::Debug(const std::string &strdebug)
{
    *outstream << "LOGGER[DEBUG]: " + strdebug + "\n";
}

void Logger::Info(const std::string &strmsg)
{
    *outstream << "LOGGER[INFO]: " << strmsg << "\n";
}

void Logger::Warning(const std::string &strwarn)
{
    *outstream << "LOGGER[WARNING]: " << strwarn << "\n";
}

void Logger::Error(const std::string &strerr)
{
    *errstream << "LOGGER[ERROR]: " << strerr << "\n";
}