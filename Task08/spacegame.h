#ifndef SPACEGAME_H
#define SPACEGAME_H

#include <string>
#include <map>

#include "target.h"
#include "../common/log.h"

class SpaceGame
{
public:
    template<typename T>
    T* addEntity(std::string name, Position pos) {
         m_entities[ name ] = new T( name, pos );
         Log::debug( "Created Target " + name + " at position " + pos.toString() );
         // TODO check positions
         return (T*) m_entities[ name ];
    }

    template<typename T>
    void addEntity( T* const entity) {
        m_entities[ ((Target*) entity)->name() ] = entity;
        Log::debug( "Created Target " + ((Target*) entity)->name() + " at position " + ((Target*) entity)->position().toString() );
    }

    void removeEntity(Target* entity);

private:
    std::map<std::string, Target*> m_entities;
};

#endif // SPACEGAME_H
