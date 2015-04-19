#ifndef SCOPETIMER_H
#define SCOPETIMER_H

#include <time.h>
#include <ctime>
#include <chrono>

using namespace std;

class ScopeTimer
{
private:
    time_t startTime;
    clock_t startClock;
    chrono::steady_clock::time_point startChrono;
public:
    ScopeTimer();
    ~ScopeTimer();
};

#endif // SCOPETIMER_H
