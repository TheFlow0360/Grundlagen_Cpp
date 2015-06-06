#ifndef DEATHSTAR_H
#define DEATHSTAR_H

#include "spaceship.h"

#define DEATHSTAR_HITPOINTS 1000000

class Deathstar : public Spaceship
{
public:
    Deathstar(std::string name, Position pos) : Spaceship( name, pos, DEATHSTAR_HITPOINTS, 50, 0 ) {}

    virtual void doDamageCalc( unsigned int dmgPoints, Target& attacker );

    virtual std::string toString() const;
protected:
    virtual void explode();
};

#endif // DEATHSTAR_H
