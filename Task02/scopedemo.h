#ifndef SCOPEDEMO_H
#define SCOPEDEMO_H

#include "../common/taskbase.h"

class ScopeDemo : public TaskBase
{
private:
    void loopDemo();
    void sleepDemo();
    void adventureDemo();

    void doAllTheHeavyWork();
    void heavyWork1();
    int heavyWork2( int n0, int n1 );
    int heavyWork3( int n0, int n1 );
public:
    ScopeDemo();
    void start();
};

#endif // SCOPEDEMO_H
