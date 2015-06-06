#include "targetmock.h"

void TargetMock::attack(Target &target)
{
    attackCount++;
}

void TargetMock::doDamageCalc(unsigned int dmgPoints, Target &attacker)
{

}

std::string TargetMock::toString() const
{
    return "";
}

void TargetMock::explode()
{

}
