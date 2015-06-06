#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "target.h"

class Spaceship : public Target
{
public:
    Spaceship(std::string name, Position pos) : Target( name, pos ) {}
};

#endif // SPACESHIP_H
