#include <QTest>

#include <QStringList>
#include <QDir>
#include <iostream>

#include "test_planet.h"
#include "test_spaceship.h"
#include "test_deathstar.h"

#define ARGUMENT_WRITE "-wtf"
#define ARGUMENT_WRITE_VERBOSE "--write-to-files"

int main(int argc, char *argv[])
{
    QStringList args;
    QString path = "";
    bool write = false;

    if ( argc > 1 ) {
        if ( !( argv[ 1 ] == std::string( ARGUMENT_WRITE )) && !(  argv[ 1 ] == std::string( ARGUMENT_WRITE_VERBOSE ) ) ) {
            std::cout << "Wrong parameters!" << std::endl << "Usage: " << argv[0] << " [-wtf] [path]" << std::endl;
            std::cout << "\t" << ARGUMENT_WRITE << "\t(" << ARGUMENT_WRITE_VERBOSE << ")\tWrite test results in files." << std::endl;
            return EXIT_FAILURE;
        }
        write = true;

        if ( argc > 2 ) {
            path = argv[ 2 ];
        } else {
            QDir qtestLogDir;
            path = "TestResults";
            qtestLogDir.mkdir( path );
        }

    }
    int status = 0;
    {
        PlanetTest tc;
        if ( write ) {
            args << "-v1" << "-o" << ( path + "/PlanetTests.log" );
        }
        status |= QTest::qExec( &tc, args );
        args.clear();
    }
    {
        SpaceshipTest tc;
        if ( write ) {
            args << "-v1" << "-o" << ( path + "/SpaceshipTest.log" );
        }
        status |= QTest::qExec( &tc, args );
        args.clear();
    }
    {
        DeathstarTest tc;
        if ( write ) {
            args << "-v1" << "-o" << ( path + "/DeathstarTest.log" );
        }
        status |= QTest::qExec( &tc, args );
        args.clear();
    }
    if ( status ) {
        std::cout << "There were errors." << std::endl;
    }
    return status;
}
