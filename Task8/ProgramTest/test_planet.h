#ifndef TEST_PLANET_H
#define TEST_PLANET_H

#include <QObject>
#include <QString>
#include <QtTest>

#include "programtest.h"
#include "../target.h"
#include "../planet.h"

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

class PlanetTest : public QObject
{
    Q_OBJECT
private:
    Planet* m_sut;

    BASE_TEST_CLASS

private Q_SLOTS:
    void initTestCase() { initTestEnv(); }
    void cleanupTestCase() { cleanupTestEnv(); }

    void init();
    void cleanup();

    void test_setPosition_NoAction();
    void test_attack_NoAction();
    void test_damage_other_NoEffect();
    void test_damage_deathstar_Destroyed();
    void test_streamOut_Success();
};

#endif // TEST_PLANET_H
