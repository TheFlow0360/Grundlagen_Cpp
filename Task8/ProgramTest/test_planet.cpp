#include "test_planet.h"

#include <QTest>
#include <sstream>
#include "targetmock.h"
#include "../spaceship.h"
#include "../deathstar.h"

void PlanetTest::init()
{
    m_sut = m_testEnv->addEntity<Planet>( TESTVALUE_NAME, m_testPosition );
}

void PlanetTest::cleanup()
{
    m_testEnv->removeEntity( m_sut );
}

void PlanetTest::test_setPosition_Failure()
{
    QCOMPARE( m_sut->position().toString(), m_testPosition.toString() );
    Position newPos;
    m_sut->setPosition( newPos );
    QCOMPARE( m_sut->position().toString(), m_testPosition.toString() );
}

void PlanetTest::test_attack_Failure()
{
    TargetMock dummy;
    m_sut->attack( dummy );

    QVERIFY2( dummy.attackCount == 0, "Planet was able to attack" );
}

void PlanetTest::test_damage_Failure()
{
    Spaceship attacker( "Spaceship", Position( 0, 0, 0 ) );
    attacker.attack( *m_sut );

    QVERIFY2( m_sut->hitpoints() == 1, "Planet hitpoints changed after normal attack" );
    QVERIFY2( !m_sut->isDestroyed(), "Planet was destroyed by normal attack" );
}

void PlanetTest::test_damage_Success()
{
    Deathstar attacker( "Deathstar", Position( 0, 0, 0 ) );
    attacker.attack( *m_sut );

    QVERIFY2( m_sut->hitpoints() == 0, "Planet has hitpoints after attack by Deathstar" );
    QVERIFY2( m_sut->isDestroyed(), "Planet survived attack of Deathstar");
}

void PlanetTest::test_streamOut_Success()
{
    std::stringstream testStream;
    testStream << *m_sut;
    std::string out = testStream.str();
    QVERIFY2( out.size() != 0, "Output stream is empty" );
    QVERIFY2( out.find( m_sut->name() ) != std::string::npos, "Name not included in output stream" );
    QVERIFY2( out.find( m_sut->position().toString() ) != std::string::npos, "Position not included in output stream" );
}
