#ifndef TARGET_H
#define TARGET_H

#include <string>

struct Position {
    double x;
    double y;
    double z;

    Position() : x(0), y(0), z(0) {}
    Position(double const x, double const y, double const z) : x(x), y(y), z(z) {}

    std::string toString() const;
    double getDistance(Position& pos2) const;
};

class Target
{
public:
    Target(std::string name, Position pos, unsigned int const hitpoints) : m_name(name), m_position( pos ), m_hitpoints( hitpoints ) {}

    virtual std::string name();
    Position position() const;
    unsigned int hitpoints() const;

    virtual void setPosition(const Position &position);

    virtual void attack( Target& target ) = 0;
    void damage( unsigned int dmgPoints, Target& attacker );
    virtual void doDamageCalc( unsigned int dmgPoints, Target& attacker );

    virtual bool isDestroyed() const;

    virtual std::string toString() const = 0;

protected:
    std::string const m_name;
    Position m_position;
    unsigned int m_hitpoints;

    virtual void explode() = 0;
};

std::ostream& operator<< (std::ostream& stream, const Position& p);

std::ostream& operator<< (std::ostream& stream, const Target& t);

#endif // TARGET_H
