#define _CRT_SECURE_NO_WARNINGS	// For Windows-Users (ctime gets warnings) - all other can delete or ignore this line
#include <ctime>

#include "logger.h"
#include "policy.h"

/// \brief Helper function to get a time-string with second resolution.
static std::string getTimeString()
{
	std::string timeStr;
	time_t rawTime;
	time( &rawTime );
	timeStr = ctime( &rawTime );
	return timeStr.substr( 0 , timeStr.size() - 1 );
}


void Logger::write(const std::string &file, long line, const std::string &message)
{
    // TODO
    getTimeString();
}
