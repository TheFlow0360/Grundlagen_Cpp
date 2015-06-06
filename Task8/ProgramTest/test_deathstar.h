#ifndef TEST_DEATHSTAR_H
#define TEST_DEATHSTAR_H

#include <QObject>
#include <QString>
#include <QtTest>

#include "programtest.h"
#include "../target.h"
#include "../deathstar.h"

// Target.
// Every Target has a position and name.
// Each target can be attacked and can explode
// Exploding cannot be triggered from outside the class. (only through receiving damage)
// Should have a stream out operator.
// Can be purely virtual (abstract).

// Deathstar
// Inherits from Spaceship
// Has far higher shields
// Can be damaged by spaceships with a 25% chance of exploding directly (without needing to get the shields to zero).
//        (- the reactor core can be hit through the exhaust vent. ;) )

class DeathstarTest : public QObject
{
    Q_OBJECT
private:
    Deathstar* m_sut;

    BASE_TEST_CLASS

private Q_SLOTS:
    void initTestCase() { initTestEnv(); }
    void cleanupTestCase() { cleanupTestEnv(); }

    void init();
    void cleanup();

    //void testPlanet();
    //void testSpaceship();
    //void testDeathstar();
};

#endif // TEST_DEATHSTAR_H
