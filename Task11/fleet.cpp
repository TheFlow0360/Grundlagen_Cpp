#include "fleet.h"
#include "spaceshipfactory.h"

#include <fstream>
#include <assert.h>

Fleet::Fleet(const std::string& fleetFilename)
{
	// TODO:
	// * Open textfile in "fleetFilename"
	// * Parse line by line:
	// ** Separate in shipname and parameter at the first ' '
	// ** call SpaceShipFactory::getInstance().buildSpaceShip
	// ** push into m_spaceShips if a new ship was successfully created
}