#ifndef PLANET_H
#define PLANET_H

#include "target.h"

class Planet : public Target
{
public:
    Planet(std::string name, Position pos) : Target( name, pos )  {}
};

#endif // PLANET_H
