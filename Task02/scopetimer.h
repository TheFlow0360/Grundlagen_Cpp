#ifndef SCOPETIMER_H
#define SCOPETIMER_H

#include <time.h>
#include <string>
#include <ctime>
#include <chrono>

#define MEASURESCOPETIME ScopeTimer measurement( __FILE__, __LINE__, __func__ );

using namespace std;

class ScopeTimer
{
private:
    int line;
    string file;
    string func;
    time_t startTime;
    clock_t startClock;
    chrono::steady_clock::time_point startChronoSteady;
    chrono::system_clock::time_point startChronoSystem;
public:
    ScopeTimer(string const aFile, int const aLine, string const aFunction);
    ~ScopeTimer();
};

#endif // SCOPETIMER_H
