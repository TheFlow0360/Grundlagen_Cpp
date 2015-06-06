#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "target.h"

#define DEFAULT_HITPOINTS 100

class Spaceship : public Target
{
public:
    Spaceship(std::string name, Position pos) : Target( name, pos, DEFAULT_HITPOINTS ) {}
    Spaceship(std::string name, Position pos, unsigned int const hitpoints) : Target( name, pos, hitpoints ) {}

    virtual void attack( Target& target );

    virtual std::string toString() const;
protected:
    virtual void explode();
};

#endif // SPACESHIP_H
