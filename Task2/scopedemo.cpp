#include "scopedemo.h"

#include <iostream>
#include <chrono>
#include <thread>
#include "scopetimer.h"
#include "../common/mathtools.h"
#include "../Task1/adventure.h"

using namespace std;

ScopeDemo::ScopeDemo()
{
}

void ScopeDemo::start()
{
    MEASURESCOPETIME

    cout << "Executing loop in a scope..." << endl;
    this_thread::sleep_for( chrono::milliseconds( 1000 ) );
    cout << "GO!" << endl;
    ScopeDemo::loopDemo();
    this_thread::sleep_for( chrono::milliseconds( 3000 ) );

    cout << "Executing sleep in a scope..." << endl;
    this_thread::sleep_for( chrono::milliseconds( 1000 ) );
    cout << "GO!" << endl;
    ScopeDemo::sleepDemo();
    this_thread::sleep_for( chrono::milliseconds( 3000 ) );

    cout << "Executing Task 1 (Adventure) in a scope..." << endl;
    this_thread::sleep_for( chrono::milliseconds( 1000 ) );
    ScopeDemo::adventureDemo();
    this_thread::sleep_for( chrono::milliseconds( 3000 ) );

    cout << "Finished ScopeDemo";
}


void ScopeDemo::loopDemo()
{
    MEASURESCOPETIME

    for ( int i = 0; i < ( 100000 + MathTools::randUInt(0, 100000) ); i++ ) {
        MathTools::fac(50);
        cout << "." << flush;
    }
}

void ScopeDemo::sleepDemo()
{
    MEASURESCOPETIME

    this_thread::sleep_for( chrono::milliseconds( 1000 + MathTools::randUInt(0, 5000) ) );
}

void ScopeDemo::adventureDemo()
{
    MEASURESCOPETIME

    Adventure adventure;
    adventure.start();
}
