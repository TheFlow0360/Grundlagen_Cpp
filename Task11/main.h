#ifndef MAIN_H
#define MAIN_H

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


#endif // MAIN_H
