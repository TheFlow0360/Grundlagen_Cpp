#include "scopetimer.h"

#include <iostream>
#include <cstdint>
#include <ctime>
#include <chrono>

using namespace std;

ScopeTimer::ScopeTimer()
{
    time(&this->startTime);
    this->startClock = clock();
    this->startChrono = chrono::steady_clock::now();
}

ScopeTimer::~ScopeTimer()
{
    time_t endTime;
    time(&endTime);
    clock_t endClock = clock();
    chrono::steady_clock::time_point endChrono = chrono::steady_clock::now();

    cout << endl;

    // via time()
    double timeDiff = difftime( endTime, startTime );
    cout << "End of Scope: It took " << timeDiff << " seconds. Measurement via time()" << endl;

    // via clock()
    double clockDiff = double( endClock - startClock ) / CLOCKS_PER_SEC;
    cout << "End of Scope: It took " << clockDiff << " seconds. Measurement via clock()" << endl;

    // via chrono
    uint64_t chronoDiffMilli = chrono::duration_cast<chrono::milliseconds>( endChrono - startChrono ).count();
    uint64_t chronoDiffMicro = chrono::duration_cast<chrono::microseconds>( endChrono - startChrono ).count();
    uint64_t chronoDiffNano = chrono::duration_cast<chrono::nanoseconds>( endChrono - startChrono ).count();
    cout << "End of Scope: It took " << chronoDiffMilli << " milliseconds / " << chronoDiffMicro << " microseconds / " << chronoDiffNano << " nanoseconds. Measurement via chrono::steady_clock" << endl;

    cout << endl;
}
