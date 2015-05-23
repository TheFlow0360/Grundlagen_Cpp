#include "node.h"

std::ostream &operator<<(std::ostream& stream, const Node& n)
{
    return stream << n.toString();
}
