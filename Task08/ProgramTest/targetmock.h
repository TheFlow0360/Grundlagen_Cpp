#ifndef TARGETMOCK_H
#define TARGETMOCK_H

#include <string>
#include "../target.h"

class TargetMock : public Target
{
public:
    TargetMock() : Target( "Mock", Position(), 1 ) {}

    virtual void attack( Target& target );
    virtual void doDamageCalc( unsigned int dmgPoints, Target& attacker );

    virtual std::string toString() const;

    unsigned int attackCount = 0;
protected:
    virtual void explode();
};

#endif // TARGETMOCK_H
