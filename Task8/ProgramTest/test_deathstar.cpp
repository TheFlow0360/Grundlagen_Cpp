#include "test_deathstar.h"

#include <sstream>
#include "../planet.h"
#include "targetmock.h"

void DeathstarTest::init()
{
    m_sut = m_testEnv->addEntity<Deathstar>( "Deathstar", m_testPosition );
}

void DeathstarTest::cleanup()
{
    m_testEnv->removeEntity( m_sut );
}

void DeathstarTest::test_setPosition_Success()
{
    QCOMPARE( m_sut->position().toString(), m_testPosition.toString() );
    Position newPos;
    m_sut->setPosition( newPos );
    QCOMPARE( m_sut->position().toString(), newPos.toString() );
}

void DeathstarTest::test_attack_planet_Destroyed()
{
    Planet* planet = m_testEnv->addEntity<Planet>( "Planet", Position() );

    m_sut->attack( *planet );

    QVERIFY2( planet->isDestroyed(), "Planet has hitpoints left after attack from the Death Star" );
    QVERIFY2( planet->hitpoints() == 0, "Planet has hitpoints left after attack from the Death Star" );
}

void DeathstarTest::test_attack_other_Success()
{
    TargetMock dummy;
    m_testEnv->addEntity( &dummy );

    m_sut->attack( dummy );

    QVERIFY2( dummy.hitpoints() == 100, "Damage dealt was incorrect, should be 100" );
}

void DeathstarTest::test_damage_normal_MinorDamageOrEffect()
{
    Spaceship* aWing = new Spaceship( "A-Wing", Position(), 30, 2, 0 );
    m_testEnv->addEntity( aWing );

    for ( unsigned int i = 0; i < 100; i++ ) {
        aWing->attack( *m_sut );
    }

    m_testEnv->removeEntity( aWing );

    QVERIFY2( m_sut->hitpoints() == ( DEATHSTAR_HITPOINTS - ( 200 * LASER_DAMAGE ) ), "Minor damage to Death Star caused incorrect hitpoints" );
    QVERIFY2( !m_sut->isDestroyed(), "Minor damage destroyed the Death Star" );

    Spaceship* yWing = new Spaceship( "Y-Wing", Position(), 50, 1, 2 );
    m_testEnv->addEntity( yWing );

    for ( unsigned int i = 0; i < 1000; i++ ) {
        yWing->attack( *m_sut );
        if ( m_sut->isDestroyed() )
            break;
    }
    m_testEnv->removeEntity( yWing );

    QVERIFY2( m_sut->hitpoints() == 0, "Death star has more than 0 hitpoints after 1000 tries with torpedos - maybe just bad luck?" );
    QVERIFY2( m_sut->isDestroyed(), "Death star not destroyed after 1000 tries with torpedos - maybe just bad luck?" );
}

void DeathstarTest::test_damage_huge_Destroyed()
{
    Spaceship* leviathan = new Spaceship( "Leviathan", Position(), 100000, 1000000000, 0 );
    m_testEnv->addEntity( leviathan );

    leviathan->attack( *m_sut );

    m_testEnv->removeEntity( leviathan );

    QVERIFY2( m_sut->hitpoints() == 0, "1 billion+ damage didn't destory the Death Star" );
    QVERIFY2( m_sut->isDestroyed(), "DeathStar wasn't destroyed after taking 1 billion+ damage");
}

void DeathstarTest::test_streamOut_Success()
{
    std::stringstream testStream;
    testStream << *m_sut;
    std::string out = testStream.str();
    QVERIFY2( out.size() != 0, "Output stream is empty" );
    QVERIFY2( out.find( m_sut->name() ) != std::string::npos, "Name not included in output stream" );
    QVERIFY2( out.find( m_sut->position().toString() ) != std::string::npos, "Position not included in output stream" );
}
