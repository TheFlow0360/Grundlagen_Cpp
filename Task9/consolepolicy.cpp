#include <iostream>

#include "consolepolicy.h"

void ConsolePolicy::write( const std::string& message )
{
	std::cerr << message << std::endl;
}
