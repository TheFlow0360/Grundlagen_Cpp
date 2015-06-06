#include "planet.h"

#include <sstream>
#include <iostream>
#include <typeinfo>
#include "../common/log.h"
#include "deathstar.h"

void Planet::setPosition(const Position &position)
{
    (void) position;
}

void Planet::attack(Target &target)
{
    Log::debug( "Planet " + m_name + " tried to attack " + target.name() );
}

void Planet::doDamageCalc(unsigned int dmgPoints, Target &attacker)
{
    (void) dmgPoints;
    if (typeid(attacker) == typeid(Deathstar)) {
        m_hitpoints--;
        std::cout << this->m_name << " gets hit by the massive beam of " << attacker.name() << "." << std::endl;
    } else {
        std::cout << "The attack of " << attacker.name() << " enters the atmosphere of " << m_name << " and goes out of sight." << std::endl;
    }
}

std::string Planet::toString() const
{
    std::stringstream stream;
    stream << "[Planet] " << m_name << " (Position " << m_position << ")" << std::endl;
    return stream.str();
}

void Planet::explode()
{
    Target::explode();
    std::cout << this->m_name << " vanishes in a violent explosion!" << std::endl;
}
