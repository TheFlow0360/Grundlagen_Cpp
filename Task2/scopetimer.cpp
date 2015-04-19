#include "scopetimer.h"

#include <iostream>
#include <cstdint>
#include <ctime>
#include <chrono>
#include <string>

using namespace std;

ScopeTimer::ScopeTimer(string const aFile, int const aLine, string const aFunction)
{
    this->file = aFile;
    this->line = aLine;
    this->func = aFunction;
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

    cout << "End of scope for Scope Timer created in " << file << " at line " << line << " (function " << func << ")" << endl;

    // via time()
    double timeDiff = difftime( endTime, startTime );
    cout << "It took " << timeDiff << " seconds. Measurement via time()" << endl;

    // via clock()
    double clockDiff = double( endClock - startClock ) / CLOCKS_PER_SEC;
    cout << "It took " << clockDiff << " seconds. Measurement via clock()" << endl;

    // via chrono
    uint64_t chronoDiffMilli = chrono::duration_cast<chrono::milliseconds>( endChrono - startChrono ).count();
    uint64_t chronoDiffMicro = chrono::duration_cast<chrono::microseconds>( endChrono - startChrono ).count();
    uint64_t chronoDiffNano = chrono::duration_cast<chrono::nanoseconds>( endChrono - startChrono ).count();
    cout << "It took " << chronoDiffMilli << " milliseconds / " << chronoDiffMicro << " microseconds / " << chronoDiffNano << " nanoseconds. Measurement via chrono::steady_clock" << endl;

    cout << endl;
}
