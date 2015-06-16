#include "logger.h"

#define _CRT_SECURE_NO_WARNINGS	// For Windows-Users (ctime gets warnings) - all other can delete or ignore this line
#include <ctime>
#include <assert.h>

#include "policy.h"

std::unique_ptr<Logger> Logger::f_instance( new Logger() );


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
    std::stringstream msgStream;
    std::string fullMsg;

    msgStream << getTimeString() << " [" << file << " : " << line << "] " << message << std::endl;

    fullMsg = msgStream.str();
    m_history += fullMsg;

    for ( auto & p : m_policies ) {
        p->write( fullMsg );
    }
}

void Logger::registerPolicy(std::unique_ptr<Policy> _policy)
{
    m_policies.push_back( std::move( _policy ) );
    m_policies.at( m_policies.size() - 1 )->write( m_history );
}

Logger &Logger::instance()
{
    return *(Logger::f_instance);
}
