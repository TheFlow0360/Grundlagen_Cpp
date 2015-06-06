#include "log.h"

#include <ctime>

std::string Log::logFilePath = DEFAULT_LOGFILE;

void Log::error(std::string const msg)
{
    #ifdef DEBUG
    std::streambuf logfile;
    logfile = std::cout;
    #else
    std::ofstream logfile;
    logfile.open( logFilePath.c_str(), std::ofstream::out | std::ofstream::app );

    #endif
    logfile << currentDateTime() <<  " [ERROR]:\t" << msg << "\n";
    logfile.close();

    throw std::exception();
}

void Log::setLogfile(std::string path)
{
    Log::logFilePath = path;
}

void Log::warning(std::string const msg)
{
    #ifdef DEBUG
    std::streambuf logfile;
    logfile = std::cout;
    #else
    std::ofstream logfile;
    logfile.open( logFilePath.c_str(), std::ofstream::out | std::ofstream::app );

    #endif
    logfile << currentDateTime() <<  " [WARNING]:\t" << msg << "\n";
    logfile.close();
}

const std::string Log::currentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

