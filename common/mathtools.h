#ifndef MATHTOOLS_H
#define MATHTOOLS_H

#include <cstdint>

class MathTools
{
public:
    MathTools();
    static unsigned int randUInt(unsigned int aMin, unsigned int aMax);
    static uint64_t fac(unsigned int aValue);
};

#endif // MATHTOOLS_H
