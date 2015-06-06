#include "target.h"

#include <sstream>
#include <iostream>
#include <cmath>

std::string Target::name()
{
    return m_name;
}

Position Target::position() const
{
    return m_position;
}

void Target::setPosition(const Position &position)
{
    m_position.x = position.x;
    m_position.y = position.y;
    m_position.z = position.z;
}

void Target::damage(unsigned int dmgPoints, Target &attacker)
{
    if ( isDestroyed() ) {
        std::cout << name() << " is already destroyed. The attack of " << attacker.name() << " hits the debris and scatters it." << std::endl;
        return;
    }
    doDamageCalc( dmgPoints, attacker );
    if ( isDestroyed() )
        explode();
}

void Target::doDamageCalc(unsigned int dmgPoints, Target &attacker)
{
    if ( dmgPoints > 0 ) {
        std::cout << name() << " gets hit by the attack of " << attacker.name() << " and takes " << dmgPoints << " points of damage." << std::endl;
    if ( dmgPoints >= m_hitpoints )
        m_hitpoints = 0;
    else
        m_hitpoints -= dmgPoints;

    } else {
        std::cout << name() << " is unaffected by the attack of " << attacker.name() << "." << std::endl;
    }
}

bool Target::isDestroyed() const
{
    return m_hitpoints == 0;
}

void Target::explode()
{
    m_hitpoints = 0;  // just to be sure
}

std::string Target::getHealthBar() const
{
    std::stringstream stream;
    stream << "[";
    unsigned int perc = ( HEALTHBAR_SIZE * m_hitpoints ) / m_maxHitpoints;
    for ( unsigned int i = 0; i < perc; i++ )
        stream << "#";
    for ( unsigned int i = perc; i < HEALTHBAR_SIZE ; i++ )
        stream << " ";
    stream << "]" << std::endl << "Hitpoints: " << m_hitpoints << " / " << m_maxHitpoints << std::endl;
    return stream.str();
}

unsigned int Target::hitpoints() const
{
    return m_hitpoints;
}

std::ostream& operator<<(std::ostream& stream, Target const& t)
{
    return stream << t.toString();
}

std::string Position::toString() const
{
    std::stringstream stream;
    stream << "[" << this->x << ", " << this->y << ", " << this->z << "]";
    return stream.str();
}

double Position::getDistance(Position const& pos2) const
{
    return sqrt( pow( this->x - pos2.x, 2 ) + pow( this->y - pos2.y, 2 ) + pow( this->y - pos2.y, 2 ) );
}

std::ostream& operator<<(std::ostream &stream, Position const& p)
{
    return stream << p.toString();
}
