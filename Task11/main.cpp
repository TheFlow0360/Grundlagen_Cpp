#include "main.h"

#include "spaceshipfactory.h"
#include "spaceships.h"
#include "fleet.h"

void Task11::AbstractFleetFactory::start()
{
	// Register SpaceShips by using the SpaceShipFactory::getInstance().registerSpaceShipType with lambda functions.

	// TODO: Register TieFighter with SpaceShipFactory::getInstance().registerSpaceShipType
	// The string parameter contains the pilot.
	
	// TODO: Register DeathStar
	// The string parameter has to be interpreted as a float, determining its buildProgress

	// TODO: Register Destroyer
	// The string parameter has to be interpreted as an int, determining the number of lasers
	// Note that the appropriate parameterized instance of the "Destroyer"-class should be created.
	
	// TODO: Register LargeDestroyer
	// The string parameter has to be interpreted as an int, determining the number of lasers.
	// Note that the appropriate parameterized instance of the "Destroyer"-class should be created.


	// Loads fleet from file
    Fleet imperialFleet("imperialships.txt");
}

Task11::AbstractFleetFactory::AbstractFleetFactory()
{
}
