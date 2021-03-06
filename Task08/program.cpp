// Task: write a program that handles interactions between planets, spaceships and deathstars
// Do this with unit tests.
// Step 1. Write Unit Tests for each class and functionality first. 
// Step 2. Write the classes and functions until each unit test passes.
//         - Also write error, debug and status output. 
//         - Each function should have error logging as well as "in-game" output. ("Deathstar was destroyed")
// Step 3. Test your work with the unit tests.
// 
// Note: Use exceptions and asserts where necessary / appropriate to test for programming and user errors.
// BONUS: write error logs to a seperate file, only display "normal" output in the console.

// Classes: Target, Planet, Spaceship and Deathstar. 
// Planet, Spaceship and Deathstar are all be targets. 

// Target.
// Every Target has a position and name. 
// Each target can be attacked and can explode
// Exploding cannot be triggered from outside the class. (only through receiving damage)
// Should have a stream out operator. 
// Can be purely virtual (abstract).

// Planet
// Inherits from Target
// Can only be destroyed be Deathstars.
// Planets cannot attack

// Spaceship
// Inherits from Target
// Has a number of lasers
// Has shields (percentage)
// Can attack other targets
// When attacked, shields are damaged. When shields <= 0, it explodes.

// Deathstar
// Inherits from Spaceship
// Has far higher shields
// Can be damaged by spaceships with a 25% chance of exploding directly (without needing to get the shields to zero).
//        (- the reactor core can be hit through the exhaust vent. ;) )       

#include <iostream>

#include "../common/consoletools.h"
#include "program.h"
#include "spacegame.h"
#include "target.h"
#include "planet.h"
#include "deathstar.h"
#include "spaceship.h"

using namespace std;

namespace Task8 {

    Program::Program()
    {}

    void Program::start()
    {
        BorderSymbols infoBorder( '|', '=', CornerSymbols( '/', '\\', '\\', '/' ) );
        SpaceGame universe;

        Planet* coruscant = universe.addEntity<Planet>( "Coruscant", Position() );
        Deathstar* deathstar = universe.addEntity<Deathstar>( "WhyTheFuckDoINeedAName", Position( 100, 100, 0 ) );
        Spaceship* tFighter = universe.addEntity<Spaceship>( "T-Fighter", Position( 95, 95, 0 ) );
        Spaceship* xWing = new Spaceship( "X-Wing", Position( -200, -150, 20 ), 35, 4, 1);
        universe.addEntity( xWing );
        Spaceship* battlecruiser = new Spaceship( "Coruscant battlecruiser", Position( 50, 50, 0 ), 500, 20, 5);
        universe.addEntity( battlecruiser );

        ConsoleTools::clearScreen();
        ConsoleTools::printBox( "Battle of Coruscant", "Test scenario for Task 8. Some ships, one planet, different attacks. Much boom, so wow.");
        ConsoleTools::printBox( "Current situation", infoBorder );
        cout << *coruscant;
        cout << "defended by: " << endl << *battlecruiser << "Current distance: " << coruscant->position().getDistance( battlecruiser->position() ) << endl << endl;
        cout << "Support incoming: " << endl << *xWing << "Current distance: " << coruscant->position().getDistance( xWing->position() ) << endl << endl;
        cout << "Enemies: " << endl << *deathstar << "Current distance: " << coruscant->position().getDistance( deathstar->position() ) << endl << endl;
        cout << *tFighter << "Current distance: " << coruscant->position().getDistance( tFighter->position() ) << endl << endl;

        ConsoleTools::printBox( "Fight", infoBorder );

        while ( !tFighter->isDestroyed() && !battlecruiser->isDestroyed() ) {
            cout << endl;
            tFighter->attack( *battlecruiser );
            cout << endl;
            battlecruiser->attack( *tFighter );
        }
        cout << endl;
        while ( !deathstar->isDestroyed() && !battlecruiser->isDestroyed() ) {
            cout << endl;
            battlecruiser->attack( *deathstar );
            cout << endl;
            deathstar->attack( *battlecruiser );
        }
    }

}
