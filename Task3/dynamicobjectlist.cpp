#include "dynamicobjectlist.h"

using namespace std;

DynamicObjectList::DynamicObjectList()
{
    m_capacity = 0;
    m_count = 0;
    this->reserve( DYNOBJLIST_START_CAPACITY );
}

DynamicObjectList::~DynamicObjectList()
{
    for ( int i = 0; i < m_count; i++ ) {
        // free the objects before relasing the references
        delete [] m_list[i];
    }
    delete[] m_list;
}


void DynamicObjectList::reserve(unsigned int aCapacity)
{
    // nothing to do if capacity already reached
    if ( aCapacity <= m_capacity ) {
        return;
    }

   Object* newList[aCapacity];

    for ( int i = 0; i < m_count; i++ ) {
        // move the old object references
        newList[i] = m_list[i];
    }

    if ( m_capacity == 0 ) {
        // free old reference list
        delete[] m_list;
    }

    m_list = (Object**) newList;
    m_capacity = aCapacity;
}

Object* DynamicObjectList::createObject_back(char* aName)
{
    if ( m_count >= m_capacity ) {
        // Extend allocation when no more space
        this->reserve( m_capacity * 2 );
    }
    return new ( m_list[m_count++] ) Object( aName );
}

void DynamicObjectList::destroyObject(unsigned int aPosition)
{
    if ( aPosition > m_count ) {
        throw new DynamicObjectListException( "No Element at this Position!" );
    }

    delete[] m_list[aPosition];
    for ( int i = aPosition + 1; i < m_count; i++ ) {
        // move references to avoid gap
        m_list[i - 1] = m_list[i];
    }
    m_count--;
}


Object* DynamicObjectList::getAt(unsigned int aPosition)
{
    if ( aPosition > m_count ) {
        throw new DynamicObjectListException( "No Element at this Position!" );
    }
    return m_list[aPosition];
}
