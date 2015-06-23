#include "spacegame.h"

#include "../common/log.h"

void SpaceGame::removeEntity(Target* entity)
{
    if ( m_entities.find( entity->name() ) != m_entities.end() ) {
        m_entities.erase( m_entities.find( entity->name() ) );
    } else {
        Log::warning( "Could not delete " + entity->name() );
    }
}
