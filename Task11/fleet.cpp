#include "fleet.h"
#include "spaceshipfactory.h"

#include <fstream>
#include <string>
#include <assert.h>

Fleet::Fleet(const std::string& fleetFilename)
{
    std::ifstream file( fleetFilename );

    std::string line;
    while ( std::getline( file, line ) )
    {
        std::string shipType, params;

        int pos = line.find( ' ', 0 );
        if ( pos <= 0 )
            continue;

        shipType = line.substr( 0, pos );
        params = line.substr( pos + 1 );

        std::shared_ptr<SpaceShip> ship( SpaceShipFactory::getInstance().buildSpaceShip( shipType, params ) );

        if ( ship == nullptr )
            continue;

        m_spaceShips.push_back( ship );

    }
}
