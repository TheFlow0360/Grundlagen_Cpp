#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "target.h"

#define DEFAULT_HITPOINTS 25
#define DEFAULT_LASER_COUNT 2
#define DEFAULT_LAUNCHER_COUNT 0

class Spaceship : public Target
{
public:
    Spaceship(std::string name, Position pos) : Target( name, pos, DEFAULT_HITPOINTS ), m_lasers(DEFAULT_LASER_COUNT), m_launchers(DEFAULT_LAUNCHER_COUNT) {}
    Spaceship(std::string name, Position pos, unsigned int const hitpoints) : Target( name, pos, hitpoints ), m_lasers(DEFAULT_LASER_COUNT), m_launchers(DEFAULT_LAUNCHER_COUNT) {}
    Spaceship(std::string name, Position pos, unsigned int const hitpoints, unsigned int const lasers, unsigned int const launchers) : Target( name, pos, hitpoints ), m_lasers(lasers), m_launchers(launchers) {}

    virtual void attack( Target& target );

    bool hasLauncher() const;

    virtual std::string toString() const;
protected:
    unsigned int m_lasers;
    unsigned int m_launchers;

    virtual void explode();
};

#endif // SPACESHIP_H
