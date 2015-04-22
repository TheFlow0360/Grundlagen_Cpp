#include "object.h"
#include <iostream>

using namespace std;

Object::Object(char* name): m_name(name)
{
  cout << "Created object with name: " << m_name << endl;
}

Object::~Object()
{
  cout << "Destroyed object with name: " << m_name << endl;
}
