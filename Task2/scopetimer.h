#ifndef SCOPETIMER_H
#define SCOPETIMER_H

#include <time.h>
#include <ctime>

using namespace std;

class ScopeTimer
{
private:
    time_t startTime;
    clock_t startClock;
public:
    ScopeTimer();
    ~ScopeTimer();
};

#endif // SCOPETIMER_H
