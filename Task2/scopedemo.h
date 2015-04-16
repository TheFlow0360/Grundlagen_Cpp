#ifndef SCOPEDEMO_H
#define SCOPEDEMO_H

#include "../common/taskbase.h"

class ScopeDemo : public TaskBase
{
private:
    void loopDemo();
    void sleepDemo();
    void adventureDemo();
public:
    ScopeDemo();
    void start();
};

#endif // SCOPEDEMO_H
