#include "filepolicy.h"

#include <fstream>

void FilePolicy::write(const std::string &message)
{
    std::ofstream stream( m_fileName, std::ofstream::out | std::ofstream::app );
    stream << message;
    stream.close();
}
