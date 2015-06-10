#ifndef TEST_SPACESHIP_H
#define TEST_SPACESHIP_H

#include <QObject>
#include <QString>
#include <QtTest>

#include "programtest.h"
#include "../target.h"
#include "../spaceship.h"

// Target.
// Every Target has a position and name.
// Each target can be attacked and can explode
// Exploding cannot be triggered from outside the class. (only through receiving damage)
// Should have a stream out operator.
// Can be purely virtual (abstract).

// Spaceship
// Inherits from Target
// Has a number of lasers
// Has shields (percentage)
// Can attack other targets
// When attacked, shields are damaged. When shields <= 0, it explodes.

class SpaceshipTest : public QObject
{
    Q_OBJECT
private:
    Spaceship* m_sut;

    BASE_TEST_CLASS

private Q_SLOTS:
    void initTestCase() { initTestEnv(); }
    void cleanupTestCase() { cleanupTestEnv(); }

    void init();
    void cleanup();

    void test_setPosition_normal_Success();
    void test_setPosition_destroyed_Failure();
    void test_attack_planet_Failure();
    void test_attack_selfDestroyed_Failure();
    void test_attack_other_Success();
    void test_damage_minor_Success();
    void test_damage_greater_Destroyed();
    void test_streamOut_Success();
};


#endif // TEST_SPACESHIP_H
