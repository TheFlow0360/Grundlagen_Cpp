#ifndef TARGET_H
#define TARGET_H

#include <string>

struct Position {
    double x;
    double y;
    double z;

    double getDistance(Position& pos2);
};

class Target
{
public:
    Target(std::string name, Position pos) : m_name(name), m_position( pos ) {}

    virtual std::string name();

    virtual Position position() const;
    virtual void setPosition(const Position &position);

protected:
    std::string const m_name;
    Position m_position;

};

#endif // TARGET_H
