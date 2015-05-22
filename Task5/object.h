#pragma once
#include <iostream>
/// This object class serves basically as dummy for an "any object".
/// Later on we will learn different possibilities how we actually could store "anything" in here.

namespace Task5 {

    class Object
    {
    public:
        Object(char const* name);
        Object(const Object&);
        ~Object();

        /// Returns ID which was passed in the constructor.
        char const* GetName() const { return m_name; }
        /// Returns whether object is const or not
        char const* GetType() const { return "Const object"; }
        char const* GetType() { return "not const"; }

        bool operator<(const Object& o) const;
        bool operator<=(const Object& o) const;
        bool operator>(const Object& o) const;
        bool operator>=(const Object& o) const;
        bool operator==(const Object& o) const;
        bool operator!=(const Object& o) const;

    private:

      char* m_name;

      // Here could be YOUR data!
    };
}

std::ostream& operator<< (std::ostream& stream, const Task5::Object&);
// implement < and > for dynamicobjectlist.sort()
