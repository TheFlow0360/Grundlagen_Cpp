#ifndef PROGRAMTEST_H
#define PROGRAMTEST_H

#include "../target.h"
#include "../spacegame.h"

#define TESTVALUE_NAME "TestTarget"
#define TESTVALUE_POSITION_X 42
#define TESTVALUE_POSITION_Y 1337
#define TESTVALUE_POSITION_Z -9001

#define BASE_TEST_CLASS SpaceGame* m_testEnv; \
    Position m_testPosition; \
\
    void initTestEnv() { \
        m_testEnv = new SpaceGame(); \
        m_testPosition.x = TESTVALUE_POSITION_X; \
        m_testPosition.y = TESTVALUE_POSITION_Y; \
        m_testPosition.z = TESTVALUE_POSITION_Z; \
    } \
    void cleanupTestEnv() { \
        delete m_testEnv; \
    } \

#endif // PROGRAMTEST_H
