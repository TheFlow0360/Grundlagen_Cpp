#include "main.h"

#include "spaceshipfactory.h"
#include "spaceships.h"
#include "fleet.h"

void Task11::AbstractFleetFactory::start()
{

    SpaceShipFactory::getInstance().registerSpaceShipType( "DeathStar", []( const std::string& param ) -> std::shared_ptr<SpaceShip>
    {
        char* e;
        float progress = std::strtod( param.c_str(), &e );
        if ( *e != 0 )
            return nullptr;
        std::shared_ptr<SpaceShip> ship( new DeathStar( progress ) );
        return ship;
    } );
    SpaceShipFactory::getInstance().registerSpaceShipType( "Destroyer", []( const std::string& param ) -> std::shared_ptr<SpaceShip>
    {
        char* e;
        int laserCount = std::strtod( param.c_str(), &e );
        if ( *e != 0 )
            return nullptr;
        std::shared_ptr<SpaceShip> ship( new Destroyer( false, laserCount ) );
        return ship;
    } );
    SpaceShipFactory::getInstance().registerSpaceShipType( "LargeDestroyer", []( const std::string& param ) -> std::shared_ptr<SpaceShip>
    {
        char* e;
        int laserCount = std::strtod( param.c_str(), &e );
        if ( *e != 0 )
            return nullptr;
        std::shared_ptr<SpaceShip> ship( new Destroyer( true, laserCount ) );
        return ship;
    } );
    SpaceShipFactory::getInstance().registerSpaceShipType( "TieFighter", []( const std::string& param ) -> std::shared_ptr<SpaceShip>
    {
        std::shared_ptr<SpaceShip> ship( new TieFighter( param ) );
        return ship;
    } );


	// Loads fleet from file
    Fleet imperialFleet("imperialships.txt");

    (void)imperialFleet;
}

Task11::AbstractFleetFactory::AbstractFleetFactory()
{
}
