#include "adventure.h"

#include <iostream>
#include "../common/consoletools.h"


Adventure::Adventure()
{}

void Adventure::Start()
{
    system("cls");
    ConsoleTools::printBox("Task 1: Adventure", "The aim is to create a simple text adventure, which means console output and basic input to decide the course of action. The application itself should be a loop, but it must have a possibility to end the game. Handling of wrong inputs is not needed.");
}
