#include "scopedemo.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
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

    cout << "Executing given demo..." << endl;
    this_thread::sleep_for( chrono::milliseconds( 1000 ) );
    ScopeDemo::doAllTheHeavyWork();
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

void ScopeDemo::heavyWork1()
{
    MEASURESCOPETIME
    for( int i = 0; i < 1000; ++i )
    {
        std::cout << "I am working\n";
    }
}

int ScopeDemo::heavyWork2( int n0, int n1 )
{
    MEASURESCOPETIME
    int freq = n1-n0+1;
    for(int i = n0; i <= n1; ++i)
    {
        // Have fun: use the alternative iteration direction and see how fast
        // it gets!
        // for(int j = 2; j < i; ++j)
        for(int j = i-1; j > 1; --j)
        {
            if(i%j == 0)
            {
                --freq;
                break;
            }
        }
    }
    return freq;
}

int ScopeDemo::heavyWork3( int n0, int n1 )
{
    MEASURESCOPETIME
    int freq = n1-n0+1;
    for(int i = n0; i <= n1; ++i)
    {
        int max = (int)sqrt(i);
        for(int j = 2; j <= max; ++j)
        {
            if(i%j == 0)
            {
                --freq;
                break;
            }
        }
    }
    return freq;
}

void ScopeDemo::doAllTheHeavyWork()
{
    MEASURESCOPETIME
    heavyWork1();
    std::cout << "Number of primes in [0, 100000]: " << heavyWork2(0, 100000) << std::endl;
    std::cout << "Number of primes in [0, 100000]: " << heavyWork3(0, 100000) << std::endl;
}
