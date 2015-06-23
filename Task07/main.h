#ifndef MAIN_H
#define MAIN_H

#include "../common/taskbase.h"
#include <string>

namespace Task7 {

    class VectorDemo : public TaskBase
    {
    public:
        VectorDemo();

        void start();
    private:
        void test(bool expr, const std::string& failmessage);
    };

}


#endif // MAIN_H
