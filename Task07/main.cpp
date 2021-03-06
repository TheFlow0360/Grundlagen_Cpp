#include "main.h"

#include <iostream>
#include "myvector.h"

namespace Task7 {

    namespace
    {
        bool fail = false;
    }

    void VectorDemo::test(bool expr, const std::string& failmessage)
    {
        if(!(expr))
        {
            std::cerr << failmessage.c_str() << std::endl;
            fail = true;
        }
    }

    VectorDemo::VectorDemo()
    {
    }

    void VectorDemo::start()
    {
        // Normal construction & constant access.
        {
            Vector<3, float> v;
            for(unsigned int i = 0; i < v.SIZE; ++i)
            {
                test(v[i] == 0, "Default constructor should initialize with zero.");
            }
        }

        // Copy construction & write access.
        {
            Vector<3, double> a;
            for(unsigned int i = 0; i < a.SIZE; ++i)
            {
                a[i] = rand();
            }
            Vector<3, double> b(a);
            for(unsigned int i = 0; i < a.SIZE; ++i)
            {
                test(a[i] == b[i], "Copy construction failed.");
            }
        }

        // Copy construction from different types.
        {
            Vector<3, double> a;
            for(unsigned int i = 0; i < a.SIZE; ++i)
            {
                a[i] = rand();
            }
            Vector<3, double> b(a);
            for(unsigned int i = 0; i < a.SIZE; ++i)
            {
                test(a[i] == b[i], "Copy construction failed.");
            }
        }

        // Construction and cast from/to string
        {
            Vector<4, int> a("42 1337 9001");
            test(a[0] == 42, "Construction from string failed");
            test(a[1] == 1337, "Construction from string failed");
            test(a[2] == 9001, "Construction from string failed");
            test(a[3] == 0, "Construction from string failed");

            Vector<5, int> b(static_cast<std::string>(a));
            for(unsigned int i = 0; i < a.SIZE; ++i)
            {
                test(a[i] == b[i], "Conversion to string failed.");
            }
        }

        // Addition
        {
            Vector<5, short> a("1 2 3 4 5");
            Vector<5, short> b("4 1 8 9 32162");

            Vector<5, short> x = a + b;

            for(unsigned int i = 0; i < a.SIZE; ++i)
            {
                test(x[i] == a[i] + b[i], "Add operator failed.");
            }
        }

        // "Conclusion"
        if(fail)
        {
            std::cerr << "\n ------- Test run failed! ------- \n";
        }
        else
        {
            std::cerr << "\n ------- All tests passed! Looks like we did not enough testing? ;) ------- \n";
        }
    }
}
