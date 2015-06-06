#ifndef OWNLOG_H
#define OWNLOG_H

#include <string>

#define DEFAULT_LOGFILE "./Logfile"

class Log
{
public:
    static void debug(std::string const msg);
    static void warning(std::string const msg);
    static void error(std::string const msg);

    static void setLogfile(std::string path);

private:
    static std::string logFilePath;

    static std::string const currentDateTime();
};

#endif // OWNLOG_H
