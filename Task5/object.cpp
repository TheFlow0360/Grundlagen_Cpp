#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "Object.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>

namespace Task5 {

    Object::Object(char const* name)
    {
        m_name = new char[strlen(name)];
        strcpy(m_name, name);
        std::cout << "Created object with name: " << m_name << std::endl;
    }
    Object::Object(const Object& o) : m_name(o.m_name)
    {
        std::cout << "Copied object with name: " << m_name << std::endl;
    }

    Object::~Object()
    {
        std::cout << "Destroyed object with name: " << m_name << std::endl;
    }

    Object &Object::operator+=(Object &o)
    {
        std::stringstream conc;
        conc << this->m_name <<  " " << o.GetName();
        std::string newName = conc.str();
        this->m_name = (char*) newName.c_str();
        return *this;
    }

    Object &Object::operator-=(Object &o)
    {
        return *this; // useless?
    }

    Object &Object::operator|=(Object &o)
    {
        return *this; // useless?
    }

    bool Object::operator<(const Object &o) const
    {
        return ( this->m_name < o.GetName() );
    }

    bool Object::operator<=(const Object &o) const
    {
        return ( this->m_name <= o.GetName() );
    }

    bool Object::operator>(const Object &o) const
    {
        return ( this->m_name > o.GetName() );
    }

    bool Object::operator>=(const Object &o) const
    {
        return ( this->m_name >= o.GetName() );
    }

    bool Object::operator==(const Object &o) const
    {
        return ( this->m_name == o.GetName() );
    }

    bool Object::operator!=(const Object &o) const
    {
        return ( this->m_name == o.GetName() );
    }

}

std::ostream& operator<< (std::ostream& stream, const Task5::Object& o)
{
	stream << "|-|" << o.GetName() << "|-|";
	return stream;
}
