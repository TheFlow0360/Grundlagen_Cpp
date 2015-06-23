#include "dynamicobjectlist.h"
#include "object.h"
#include <algorithm>

namespace Task5 {

    DynamicObjectList::DynamicObjectList() :
    m_count(0),
    m_capacity(0),
    m_list(nullptr)
    {
    }

    DynamicObjectList::~DynamicObjectList()
    {
      delete[] m_list;
    }

    void DynamicObjectList::reserve(unsigned int capacity)
    {
      // Check if anything should happen.
//      if(m_capacity >= capacity)
//        return;

      // Create new object array with the given capacity.
      Object** newArray = new Object*[capacity];

      // Moves old list contents to new list.
      for(unsigned int i = 0; i < m_count; ++i)
      {
        newArray[i] = m_list[i];
      }

      // Optional: Set all other pointer to nullptr, just for easier debugging.
      for(unsigned int i = m_count; i < capacity; ++i)
      {
        newArray[i] = nullptr;
      }

      // delete old array!
      delete[] m_list;

      // Save new data.
      m_list = newArray;
      m_capacity = capacity;
    }
    Object* DynamicObjectList::createObject_back(char* name)
    {
        // Ensure capacity.
        reserve((m_count + 1) * 2);

        // Add new object.
        m_list[m_count] = new Object(name);

        return m_list[m_count++];
    }

    void DynamicObjectList::sort()
    {
//        for (unsigned int j = 1; j < m_count-2; j++)    // Start with 1 (not 0)
//        {
//            unsigned int i = 0;
//            Object *tmp = m_list[j];
//            for (i = j - 1; (i >= 0) && (*m_list[i] < *tmp); i--)   // Smaller values move up
//            {
//                m_list[i + 1] = m_list[i];
//            }
//            m_list[i + 1] = tmp;    //Put key into its proper location
//        }
        std::sort(m_list[0], m_list[m_count - 1],
                [](const Object& a, const Object& b) -> bool
        {
            return a > b;
        } );
    }

    Object* DynamicObjectList::push_back(Object *a)
    {
        if (a == nullptr)
            return a;
        // Ensure capacity.
        reserve((m_count + 1) * 2);

        // Add new object.
        m_list[m_count] = a;

        return m_list[m_count++];
    }

    Object* DynamicObjectList::createObject_front(char* name)
    {
      // Ensure capacity.
      reserve((m_count + 1) * 2);

      // Move all other objects.
      for (unsigned int i = m_count; i >= 1; --i)
      {
        m_list[i] = m_list[i - 1];
      }

      // Add new object.
      m_list[0] = new Object(name);
      ++m_count;

      return m_list[0];
    }

    void DynamicObjectList::destroyObject(unsigned int position)
    {
      // Does the element exist?
      if(m_count <= position)
      {
        return;
      }

      // Destroy the object at the given position.
      delete m_list[position];

      // Now we have less objects!
      --m_count;

      // Move all other objects.
      for (unsigned int i = position; i < m_count; ++i)
      {
        m_list[i] = m_list[i + 1];
      }
      shrink();
      // Optional: Set former back to nullptr for easier debugging.
      m_list[m_count] = nullptr;
    }

    Object* DynamicObjectList::getAt(unsigned int position)
    {
        // Does the element exist?
        if (m_count <= position)
        {
            return nullptr;
        }

        return m_list[position];
    }

    Object* DynamicObjectList::getAt(const unsigned int position) const
    {
        // Does the element exist?
        if (m_count <= position)
        {
            return nullptr;
        }

        return m_list[position];
    }

    DynamicObjectList &DynamicObjectList::operator+=(Object& o)
    {
        this->push_back(&o);
        return *this;
    }

    DynamicObjectList &DynamicObjectList::operator|=(const DynamicObjectList& l)
    {
        for ( unsigned int i = 0; i < l.getCount(); i++ ) {
            this->push_back( l.getAt( i ) );
        }
        return *this;
    }

    DynamicObjectList &DynamicObjectList::operator&=(const DynamicObjectList& l)
    {
        std::vector<unsigned int> toDelete;
        for ( unsigned int i = 0; i < this->m_count; i++ ) {
            bool found = false;
            for ( unsigned int j = 0; j < l.getCount(); j++ ) {
                if ( this->getAt( i ) == l.getAt( j ) ) {
                    found = true;
                    break;
                }
            }
            if ( !found ) {
                toDelete.push_back( i );
            }
        }

        std::sort(toDelete.begin(), toDelete.end(), std::greater<unsigned int>() );

        for ( unsigned int i : toDelete) {
            this->destroyObject(i);
        }
        shrink();
        return *this;
    }

    Object &DynamicObjectList::operator[](unsigned int const i) const
    {
        return *( this->getAt( i ) );
    }

    Object &DynamicObjectList::operator[](unsigned int const i)
    {
        return *( this->getAt( i ) );
    }

    void DynamicObjectList::shrink()
    {
        if ( m_count == 0 ) {
            this->reserve( 1 ); // baaaaaaaaaaaaaaaaaad
            return;
        }
        if ( m_capacity > ( 5 * m_count ) ) {
        unsigned int newCapacity = m_capacity;
            do {
                newCapacity /= 2;
            } while ( ( newCapacity / 2 ) >= ( 2 * m_count ) );
        this->reserve( newCapacity );
        }
    }

}
