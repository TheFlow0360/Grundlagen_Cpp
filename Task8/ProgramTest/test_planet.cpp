#include "test_planet.h"

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

}

void PlanetTest::test_attack_Failure()
{

}

void PlanetTest::test_damage_Failure()
{

}

void PlanetTest::test_damage_Success()
{

}

void PlanetTest::test_streamOut_Success()
{

}
