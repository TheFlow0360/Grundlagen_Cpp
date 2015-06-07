#include "deathstar.h"

#include <iostream>
#include <sstream>
#include <typeinfo>
#include <chrono>

void Deathstar::doDamageCalc(unsigned int dmgPoints, Target &attacker)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count() + ( rand() % rand() );
    std::minstd_rand randGen(seed);
    std::uniform_int_distribution<> randDist(1, 12);

    //randDist(randGen); // call to get more randomness - awesome!

    if ( dmgPoints > 0 ) {
        std::cout << name() << " gets hit by the attack of " << attacker.name();
        if (typeid(attacker) == typeid(Spaceship)) {
            if ( ((Spaceship&)attacker).hasLauncher()  ) {
              if ( ( randDist(randGen) % 4 ) == 0 ) {
                  std::cout << ". A torpedo enters the heat vent and causes the destruction of the power core!" << std::endl;
                  m_hitpoints = 0;
                  std::cout << getHealthBar();
                  return;
              }
            }
        }
        if ( ( dmgPoints > 10 ) && ( m_lasers > 0 ) && ( ( randDist(randGen) % 3 ) == 0 ) ) {
            std::cout << " and destroyes a laser turret! " << m_name << " takes " << dmgPoints << " points of damage." << std::endl;
            m_lasers--;
        } else {
            std::cout << " and takes " << dmgPoints << " points of damage." << std::endl;
        }
        if ( dmgPoints >= m_hitpoints )
            m_hitpoints = 0;
        else
            m_hitpoints -= dmgPoints;
    } else {
        std::cout << name() << " is completly unaffected by the attack of " << attacker.name() << "." << std::endl;
    }
    std::cout << getHealthBar();
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
    std::cout << m_name << " is destroyed in a huge explosion." << std::endl;
}
