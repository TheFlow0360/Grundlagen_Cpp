#include "deathstar.h"

#include <iostream>
#include <sstream>
#include <random>
#include <typeinfo>

void Deathstar::doDamageCalc(unsigned int dmgPoints, Target &attacker)
{
    if ( dmgPoints > 0 ) {
        std::cout << name() << " gets hit by the attack of " << attacker.name();
        if (typeid(attacker) == typeid(Spaceship)) {
            if ( ((Spaceship&)attacker).hasLauncher()  ) {
              if ( ( rand() % 4 ) == 0 ) {
                  std::cout << ". A torpedo enters the heat vent and causes the destruction of the power core! ";
                  return;
              }
            }
        }
        if ( dmgPoints > 10 ) {
            if ( ( m_lasers > 0 ) && ( ( rand() % 3 ) == 0 ) ) {
                std::cout << " and takes destroyes a laser turret! " << m_name << " takes " << dmgPoints << " points of damage." << std::endl;
                m_lasers--;
                return;
            }
        }
        std::cout << " and takes " << dmgPoints << " points of damage." << std::endl;
        if ( dmgPoints >= m_hitpoints )
            m_hitpoints = 0;
        else
            m_hitpoints -= dmgPoints;
    } else {
        std::cout << name() << " is completly unaffected by the attack of " << attacker.name() << "." << std::endl;
    }
}

std::string Deathstar::toString() const
{
    std::stringstream stream;
    stream << "[Death Star] " << m_name << " (Position " << m_position.toString() << ")" << std::endl;
    stream << "Weapons:" << std::endl << "\t" << m_lasers << " laser turrets per direction" << std::endl << "\t1 Superlaser" << std::endl;
    stream << getHealthBar() << std::endl;
    return stream.str();
}

void Deathstar::explode()
{
    Target::explode();
    std::cout << " is destroyed in a huge explosion." << std::endl;
}
