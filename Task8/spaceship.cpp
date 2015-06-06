#include "spaceship.h"

#include <sstream>

void Spaceship::attack(Target &target)
{

}

std::string Spaceship::toString() const
{
    std::stringstream stream;
    stream << "Spaceship " << m_name << " (Position: " << m_position << ")" << std::endl;
    // TODO
    return stream.str();
}

void Spaceship::explode()
{

}
