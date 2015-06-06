#include "target.h"

#include <sstream>
#include <iostream>

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
        std::cout << name() << " gets hit by the attack of " << attacker.name() << " and takes " << dmgPoints << " points of damage.";
    if ( dmgPoints >= m_hitpoints )
        m_hitpoints = 0;
    else
        m_hitpoints -= dmgPoints;

    } else {
        std::cout << name() << " is unaffected by the attack of " << attacker.name() << ".";
    }
}

bool Target::isDestroyed() const
{
    return m_hitpoints > 0;
}
unsigned int Target::hitpoints() const
{
    return m_hitpoints;
}

std::string Position::toString() const
{
    std::stringstream str;
    str << "[" << this->x << ", " << this->y << ", " << this->z << "]";
    return str.str();
}

double Position::getDistance(Position &pos2) const
{
    return 0; // TODO
}


std::ostream &operator<<(std::ostream &stream, const Position &p)
{
    return stream << p.toString();
}


std::ostream &operator<<(std::ostream &stream, const Target &t)
{
    return stream << t.toString();
}
