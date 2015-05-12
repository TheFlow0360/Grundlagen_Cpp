#ifndef PROGRAM_H
#define PROGRAM_H

#include "../common/taskbase.h"

class Task4 : public TaskBase
{
private:
    int& sumTheElements(int a, int b);
public:
    Task4();

    void start();
};

#endif // PROGRAM_H
