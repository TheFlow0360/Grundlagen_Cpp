#include "mathtools.h"

#include <stdlib.h>
#include <cstdint>

using namespace std;

MathTools::MathTools()
{
}

unsigned int MathTools::randUInt(unsigned int aMin, unsigned int aMax)
{
    return aMin + (rand() % ((aMax - aMin) + 1));
}

uint64_t MathTools::fac(unsigned int aValue)
{
    return (aValue == 1 || aValue == 0) ? 1 : MathTools::fac(aValue - 1) * aValue;
}
