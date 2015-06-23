#ifndef PLANET_H
#define PLANET_H

#include "target.h"

class Planet : public Target
{
public:
    Planet(std::string name, Position pos) : Target( name, pos, 1 )  {}

    virtual void setPosition(const Position &position);

    virtual void attack( Target& target );
    virtual void doDamageCalc( unsigned int dmgPoints, Target& attacker );

    virtual std::string toString() const;
protected:
    virtual void explode();
};

#endif // PLANET_H
