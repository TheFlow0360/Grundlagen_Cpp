#include "spaceship.h"

#include <sstream>
#include <iostream>
#include "../common/log.h"


void Spaceship::attack(Target &target)
{
    if ( isDestroyed() ) {
        Log::debug( m_name + " tried to attack, but it's already destroyed." );

    }
    std::cout << m_name << " attacks " << target.name() << "." << std::endl;
    target.damage( m_lasers * LASER_DAMAGE + m_launchers * LAUNCHER_DAMAGE, *this );
}

bool Spaceship::hasLauncher() const
{
    return m_launchers > 0;
}

std::string Spaceship::toString() const
{
    std::stringstream stream;
    stream << "[Spaceship] " << m_name << " (Position: " << m_position << ")" << std::endl;
    stream << "Weapons:" << std::endl << "\t" << m_lasers << " laser cannons" << std::endl << "\t" << m_launchers << " torpedo launchers" << std::endl;
    stream << getHealthBar() << std::endl;
    return stream.str();
}

void Spaceship::explode()
{
    Target::explode();
    std::cout << m_name << " shields are depleted and the ship is destroyed." << std::endl;
}
