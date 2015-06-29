#ifndef TASK11_MAIN_H
#define TASK11MAIN_H

#include "../common/taskbase.h"
#include <string>

namespace Task11 {

    class AbstractFleetFactory : public TaskBase
    {
    public:
        AbstractFleetFactory();

        void start();
    };

}


#endif // TASK11_MAIN_H
