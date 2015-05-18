#ifndef PROGRAMTASK4_H
#define PROGRAMTASK4_H

#include "../common/taskbase.h"

namespace Task4 {

    class Program : public TaskBase
    {
    private:
        template <typename T>
        T& sumTheElements(T a, T b);
    public:
        Program();

        void start();
    };

}

#endif // PROGRAMTASK4_H
