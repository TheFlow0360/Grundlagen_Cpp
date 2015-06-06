#include <QTest>

#include "test_planet.h"
#include "test_spaceship.h"
#include "test_deathstar.h"

int main(int argc, char *argv[])
{
    int status = 0;
    {
        PlanetTest tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    {
        SpaceshipTest tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    {
        DeathstarTest tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    return status;
}
