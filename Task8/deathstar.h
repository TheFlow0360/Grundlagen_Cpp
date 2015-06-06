#ifndef DEATHSTAR_H
#define DEATHSTAR_H

#include "spaceship.h"

#define DEATHSTAR_HITPOINTS 1000000

class Deathstar : public Spaceship
{
public:
    Deathstar(std::string name, Position pos) : Spaceship( name, pos, DEATHSTAR_HITPOINTS ) {}

    virtual void attack( Target& target );
    virtual void doDamageCalc( unsigned int dmgPoints, Target& attacker );
protected:
    virtual void explode();
};

#endif // DEATHSTAR_H
