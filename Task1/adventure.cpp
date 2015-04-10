#include "adventure.h"

#include <iostream>
#include "../common/consoletools.h"
#include "room.h"

using namespace std;

void Adventure::loadRooms()
{
    // could be done via xml or something else...
    // main point: it should be dynamic, not hard coded rooms - sadly out of scope for this task

    Room* startRoom = new Room("You find yourself in a dark room. The walls feel sticky and there is a faint dripping sound.\nYou are lying on a shabby, cold cot. The room seems to have just one exit.");
    Room* hallway = new Room("You enter the hallway. It's lit by torches attached to the walls. You see a few doors.");
    startRoom->addOption("[L]eave the room.", "l", hallway->getId());
    hallway->addOption("Open the first [l]eft hand side door.", "l", "The door seems to be locked.");
    Room* pitfall = new Room("Behind the door is a tunnel. Far away, probably at the end of the way, you can see sunlight. There is no other source of light on the way.");
    hallway->addOption("Open the [s]econd left hand side door.", "s", pitfall->getId());
    Room* endRoom = new Room("Right after entering, the door slams shut behind you. It has no doorknob from inside.  You are trapped!\nIn front of you is a table, on top of it stands a cake. It looks delicious...");
    hallway->addOption("Open the door at your [r]ight.", "r", endRoom->getId());
    hallway->addEnd("Examine the [t]orches", "t", "AS soon as you touch one of the torches, all of the flames vanish.\nEveryting around you is pitch black. How should you find a way out of here now?", true);
    pitfall->addEnd("An Exit! [R]un towards the light.", "r", "After taking a few steps you hear a rumbling. The ground beneath you vanishes and you start to fall. The fall seems endless...", true);
    pitfall->addOption("No, it's a trap! Let's turn [b]ack", "b", hallway->getId());
    endRoom->addEnd("Eat the [c]ake!", "c", "It is REALLY delicious. But somehow... You feel sooooo..... sleepy.........", false);
    endRoom->addEnd("The cake is a [l]ie!", "l", "Lights turn on, the walls are egtting pulled away by mechanical arms.\n\"Congratulations! You successfully mastered the first test chamber of the Aparture Labs Psychological Department. Enjoy your stay in the Enrichment Center.\"", false);

    this->fRooms.push_back(*startRoom);
    this->fRooms.push_back(*hallway);
    this->fRooms.push_back(*pitfall);
    this->fRooms.push_back(*endRoom);
}

Room Adventure::getRoom(const unsigned int aId)
{
    list<Room>::iterator itr;
    for( itr = this->fRooms.begin(); itr != this->fRooms.end(); ++itr ) {
        if ( itr->getId() == aId ) {
            return (*itr);
        }
    }
    throw ERANGE;
}

Adventure::Adventure()
{
    this->loadRooms();
}

void Adventure::start()
{
    system("cls");
    ConsoleTools::printBox("Task 1: Adventure", "The aim is to create a simple text adventure, which means console output and basic input to decide the course of action. The application itself should be a loop, but it must have a possibility to end the game. Handling of wrong inputs is not needed.");
    while ( true ) {
        cout << "[S]tart the adventure or [q]uit?" << endl;
        string opt;
        cin >> opt;
        if ( ( opt == "S" ) || ( opt == "s" ) ) {
            system("cls");
            int res;
            Room active = this->fRooms.front();
            while ( true ) {
                res = active.roomExec();
                if ( res == -1 ) {
                    ConsoleTools::printBox("BAD END...");
                    break;
                } else if ( res == 0 ) {
                    ConsoleTools::printBox("GAME CLEAR!");
                    break;
                } else {
                    active = this->getRoom( (unsigned int) ( res ) );
                }
            }
        } else if ( ( opt == "Q" ) || ( opt == "q" ) || ( opt == "X" ) || ( opt == "x" ) ) {
            break;
        } else {
            cout << "Invalid input - Try again" << endl;
        }
    }
}
