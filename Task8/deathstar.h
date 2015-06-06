#ifndef DEATHSTAR_H
#define DEATHSTAR_H

#include "spaceship.h"

class Deathstar : public Spaceship
{
public:
    Deathstar(std::string name, Position pos) : Spaceship(name, pos) {}
};

#endif // DEATHSTAR_H
