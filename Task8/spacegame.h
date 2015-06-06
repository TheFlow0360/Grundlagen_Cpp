#ifndef SPACEGAME_H
#define SPACEGAME_H

#include <string>
#include <map>

#include "target.h"

class SpaceGame
{
public:
    template<typename T>
    T* addEntity(std::string name, Position pos) {
         m_entities[ name ] = new T( name, pos );
         return (T*) m_entities[ name ];
    }

    void removeEntity(Target* entity);

private:
    std::map<std::string, Target*> m_entities;
};

#endif // SPACEGAME_H
