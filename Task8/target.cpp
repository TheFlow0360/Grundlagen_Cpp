#include "target.h"

std::string Target::name()
{
    return m_name;
}

Position Target::position() const
{
    return m_position;
}

void Target::setPosition(const Position &position)
{
    m_position.x = position.x;
    m_position.y = position.y;
    m_position.z = position.z;
}


double Position::getDistance(Position &pos2)
{
    return 0; // TODO
}
