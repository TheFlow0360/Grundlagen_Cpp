#include "targetmock.h"

void TargetMock::attack(Target &target)
{
    (void) target;
    attackCount++;
}

void TargetMock::doDamageCalc(unsigned int dmgPoints, Target &attacker)
{
    (void)dmgPoints;
    (void)attacker;
}

std::string TargetMock::toString() const
{
    return "";
}

void TargetMock::explode()
{

}
