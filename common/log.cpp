#include "log.h"

#include <ctime>
#include <sstream>
#ifdef DEBUG
    #include <iostream>
#else
    #include <fstream>
#endif


std::string Log::logFilePath = DEFAULT_LOGFILE;

void Log::error(std::string const msg)
{
    std::stringstream log;
    log << currentDateTime() <<  " [ERROR]:\t" << msg << "\n";

#ifdef DEBUG
    std::cout << log;
#else
    std::ofstream logfile;
    logfile.open( logFilePath.c_str(), std::ofstream::out | std::ofstream::app );
    logfile << log;
    logfile.close();
#endif

    throw std::exception();
}

void Log::setLogfile(std::string path)
{
    Log::logFilePath = path;
}

void Log::debug(const std::string msg)
{
#ifdef DEBUG
    std::cout << currentDateTime() <<  " [DEBUG]:\t" << msg << std::endl;
#else
    (void) msg;
#endif
}

void Log::warning(std::string const msg)
{
    std::stringstream log;
    log << currentDateTime() <<  " [WARNING]:\t" << msg << "\n";

#ifdef DEBUG
    std::cout << log;
#else
    std::ofstream logfile;
    logfile.open( logFilePath.c_str(), std::ofstream::out | std::ofstream::app );
    logfile << log;
    logfile.close();
#endif
}

const std::string Log::currentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%X", &tstruct);

    return buf;
}

