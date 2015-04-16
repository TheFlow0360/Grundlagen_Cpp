#include "scopetimer.h"

#include <iostream>
#include <ctime>

using namespace std;

ScopeTimer::ScopeTimer()
{
    time(&this->startTime);
    this->startClock = clock();
}

ScopeTimer::~ScopeTimer()
{
    time_t endTime;
    time(&endTime);
    clock_t endClock = clock();

    cout << endl;

    // via time()
    double timeDiff = difftime( endTime, startTime );
    cout << "End of Scope: It took " << timeDiff << " seconds. Measurement via time()" << endl;

    // via clock()
    double clockDiff = double(endClock - startClock) / CLOCKS_PER_SEC;
    cout << "End of Scope: It took " << clockDiff << " seconds. Measurement via clock()" << endl;

    // via chrono

    cout << endl;
}
