#include "spaceshipfactory.h"

// If spaceships.h would be not included, the SpaceShip's destructor would be unknown.
// This usually leads to a warning
#include "spaceships.h"

std::shared_ptr<SpaceShip> SpaceShipFactory::buildSpaceShip(const std::string &spaceShipTypeName, const std::string &parameter)
{
    try {
        std::shared_ptr<SpaceShip> ship( ( m_createSpaceShipFuncRegister.at( spaceShipTypeName ) )( parameter ) );
        return ship;
    } catch( std::out_of_range ) {
        return nullptr;
    }
}

void SpaceShipFactory::registerSpaceShipType(const std::string &spaceShipTypeName, const SpaceShipFactory::CreateSpaceShipFunc &createSpaceShipFunc)
{
    m_createSpaceShipFuncRegister[ spaceShipTypeName ] = createSpaceShipFunc;
}
