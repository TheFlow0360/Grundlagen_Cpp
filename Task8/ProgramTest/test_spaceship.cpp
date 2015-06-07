#include "test_spaceship.h"

#include <sstream>
#include "../planet.h"

void SpaceshipTest::init()
{
    m_sut = m_testEnv->addEntity<Spaceship>( "Spaceship", m_testPosition );
}

void SpaceshipTest::cleanup()
{
    m_testEnv->removeEntity( m_sut );
}

void SpaceshipTest::test_setPosition_normal_Success()
{
    QCOMPARE( m_sut->position().toString(), m_testPosition.toString() );
    Position newPos;
    m_sut->setPosition( newPos );
    QCOMPARE( m_sut->position().toString(), newPos.toString() );
}

void SpaceshipTest::test_setPosition_destroyed_Failure()
{
    QCOMPARE( m_sut->position().toString(), m_testPosition.toString() );
    Position newPos;
    m_sut->doDamageCalc( 1000, *m_sut );
    m_sut->setPosition( newPos );
    QCOMPARE( m_sut->position().toString(), m_testPosition.toString() );
}

void SpaceshipTest::test_attack_planet_Failure()
{
    Planet* planet = m_testEnv->addEntity<Planet>( "Planet", Position() );

    m_sut->attack( *planet );

    QVERIFY2( planet->hitpoints() > 0, "Spaceship damaged a Planet" );
    QVERIFY2( !planet->isDestroyed(), "Spaceship destroyed a Planet" );

    m_testEnv->removeEntity( planet );

}

void SpaceshipTest::test_attack_other_Success()
{
    Spaceship* spaceship = m_testEnv->addEntity<Spaceship>( "Spaceship", Position() );

    m_sut->attack( *spaceship );

    QVERIFY2( spaceship->hitpoints() == ( DEFAULT_HITPOINTS - ( DEFAULT_LASER_COUNT * LASER_DAMAGE + DEFAULT_LAUNCHER_COUNT * LAUNCHER_DAMAGE ) ), "Spaceship damaged a Planet" );

    m_testEnv->removeEntity( spaceship );
}

void SpaceshipTest::test_damage_minor_Success()
{
    Spaceship* attacker = m_testEnv->addEntity<Spaceship>( "Spaceship", Position() );

    attacker->attack( *m_sut );

    m_testEnv->removeEntity( attacker );

    QVERIFY2( m_sut->hitpoints() == ( DEFAULT_HITPOINTS - ( LASER_DAMAGE * DEFAULT_LASER_COUNT + LAUNCHER_DAMAGE * DEFAULT_LAUNCHER_COUNT ) ), "Hitpoints after atatck incorrect." );
    QVERIFY2( !m_sut->isDestroyed(), "Spaceship destroyed by minor attack" );
}

void SpaceshipTest::test_damage_greater_Destroyed()
{
    Spaceship* attacker = new Spaceship( "Destroyer", Position(), 100, 100, 50 );
    m_testEnv->addEntity( attacker );

    attacker->attack( *m_sut );

    m_testEnv->removeEntity( attacker );

    QVERIFY2( m_sut->hitpoints() == 0 , "Spaceship Hitpoints after attack incorrect." );
    QVERIFY2( m_sut->isDestroyed(), "Spaceship not destroyed by a huge attack" );
}

void SpaceshipTest::test_streamOut_Success()
{
    std::stringstream testStream;
    testStream << *m_sut;
    std::string out = testStream.str();
    QVERIFY2( out.size() != 0, "Output stream is empty" );
    QVERIFY2( out.find( m_sut->name() ) != std::string::npos, "Name not included in output stream" );
    QVERIFY2( out.find( m_sut->position().toString() ) != std::string::npos, "Position not included in output stream" );
}
