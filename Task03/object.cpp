#include "object.h"
#include <iostream>

using namespace std;

namespace Task3 {

    Object::Object(char const* name): m_name(name)
    {
        cout << "Created object with name: " << m_name << endl;
    }

    Object::~Object()
    {
        cout << "Destroyed object with name: " << m_name << endl;
    }

}
