#pragma once

#include <cassert>
#include <cstdlib>
#include <memory>

/// \brief A dynamic array which uses local space as long as it isn't too large.
/// \details The array itself contains space for n elements. As long as the
///		number of elements is smaller than this local capacity there is no
///		additional memory block somewhere else. Data and meta information are
///		both part of the same block. This increases speed as long as we are
///		dealing with small arrays (<n). E.g. strings
///
///		In case there is more data the array behaves as std::vector.
///
///		As usual copying arrays is expensive.
template<typename T, unsigned n = 8>
class HybridArray
{
public:
	typedef T ElemType;

	/// \brief Standard: create this array with capacity n and size 0.
	/// \details m_data is set to the local storage.
    HybridArray();

	/// \brief Create a dynamic array with preallocated space. Probably
	///		this disables the advantage of 'hybrid':
	///	\param [in] _capacity Minimum capacity which should be allocated.
    ///		The allocated capacity must be max(_capacity, n). So there is
	///		never less than the already existing internal memory block.
	HybridArray(unsigned _capacity);

	/// \brief Copy construction (deep).
	HybridArray(const HybridArray<T,n>& _other);

	/// \brief Calls destructor for all contained elements.
	~HybridArray();

	/// \brief Deep copying assignment
	HybridArray<ElemType,n>& operator = (const HybridArray<T,n>& _other);

	/// \brief Write-array access.
    ElemType& operator[](unsigned int const pos) { return m_data[ pos ]; }

	/// \brief Read-array access.
    ElemType& operator[](unsigned int const pos) const  { return m_data[ pos ]; }

	/// \brief Enlarge or prune the memory.
	/// \details This function is already implemented. You can have a look
	///		to understand the array and to see how std::swap can be used.
	/// \param [in] _capacity New capacity/size. If _capacity is below n
	///		the new capacity is still n.
	///		
	///		A value smaller than size() causes a prune: capacity = size();
	void reserve(unsigned _capacity = 0);

	/// \brief Insert an element copy at the end of the array.
	/// \details This might cause a resize with costs O(n).
	const ElemType& pushBack(const ElemType& _element);

	/// \brief Delete the last element
	void popBack();

	unsigned size() const		{ return m_size; }
	unsigned capacity() const	{ return m_capacity; }

	/// \brief Access first element
	ElemType& front()				{ assert(m_size>0); return *m_data; }
	const ElemType& front() const	{ assert(m_size>0); return *m_data; }

	/// \brief Access last element
	ElemType& back()				{ assert(m_size>0); return m_data[m_size-1]; }
	const ElemType& back() const	{ assert(m_size>0); return m_data[m_size-1]; }
protected:
	ElemType* m_data;		///< Pointer to array memory block. Might be on stack or heap.
	unsigned m_capacity;	///< Maximum number of elements
	unsigned m_size;		///< Current number of elements

	unsigned char m_localStorage[sizeof(T)*n];	///< The local storage on stack or in object heap space.
private:
    void deepCopy(const HybridArray<T, n> &_other);
};






// ********************************************************************* //
//  HybridArray Implementation											 //
// ********************************************************************* //

template<typename T, unsigned n>
HybridArray<T,n>::HybridArray() : m_capacity(n), m_size(0) {
    m_data = reinterpret_cast<ElemType*>( &m_localStorage );
    for ( unsigned int i = 0; i < n; i++ ) {
        m_data[ i ] = 0;
    }
}

template<typename T, unsigned n>
HybridArray<T,n>::HybridArray(unsigned _capacity) : m_capacity(0), m_size(0) {
    if ( _capacity > n ) {
        reserve( _capacity );
    } else {
        m_data = reinterpret_cast<ElemType*>( &m_localStorage );
        m_capacity = n;
        for ( unsigned int i = 0; i < n; i++ ) {
            m_data[ i ] = 0;
        }
    }
}

template<typename T, unsigned n>
HybridArray<T,n>::HybridArray(const HybridArray<T, n> &_other) : m_capacity(0), m_size(0) {
    if ( _other.capacity() > n ) {
        reserve( _other.capacity() );
        deepCopy( _other );
    } else {
        m_data = reinterpret_cast<ElemType*>( &m_localStorage );
        m_capacity = n;
        for ( unsigned int i = 0; i < n; i++ ) {
            m_data[ i ] = 0;
        }
        deepCopy( _other );
    }
}

template<typename T, unsigned n>
HybridArray<T,n>::~HybridArray()
{
    for ( unsigned int i = 0; i < m_size; i++ ) {
         m_data[ i ].~ElemType();
    }
    free( m_data );
}

template<typename T, unsigned n>
HybridArray<T, n> &HybridArray<T, n>::operator =(const HybridArray<T, n> &_other)
{
    for ( unsigned int i = 0; i < m_size; i++ ) {
         m_data[ i ].~ElemType();
    }
    m_size = 0;
    reserve( _other.capacity() );

    deepCopy( _other );
    return *this;
}

template<typename T, unsigned n>
void HybridArray<T,n>::deepCopy(const HybridArray<T, n> &_other)
{
    for ( unsigned int i = 0; i < _other.size(); i++ ) {
        new ( &m_data[ i ] ) ElemType( _other[ i ] );
    }
    m_size = _other.size();
}

template<typename T, unsigned n>
T const& HybridArray<T,n>::pushBack(const HybridArray::ElemType &_element)
{
    if ( m_size >= m_capacity ) {
        reserve( 2 * m_capacity  );
    }
    return *( new ( &m_data[ m_size++ ] ) ElemType( _element ) );
}

template<typename T, unsigned n>
void HybridArray<T,n>::popBack()
{
    m_data[ m_size-- - 1 ].~ElemType();
}

// ********************************************************************* //
template<typename T, unsigned n>
void HybridArray<T,n>::reserve(unsigned _capacity)
{
	// Resizing without change. Bad Performance!
	assert(m_capacity != _capacity);

	// Prune as much as possible - do not delete data
	if( _capacity <= m_size ) _capacity = m_size;

	unsigned oldCapacity = m_capacity;
	m_capacity = _capacity < n ? n : _capacity;
	// If both old and new capacity are <= n nothing happens otherwise
	// a realloc or copy is necessary
	if( m_capacity > n || oldCapacity > n )
	{
		ElemType* oldData = m_data;

		// Determine target memory
		if( m_capacity <= n )
			m_data = reinterpret_cast<ElemType*>(m_localStorage);
		else
			m_data = (ElemType*)malloc( m_capacity * sizeof(ElemType) );

		// Now keep the old data
		for( unsigned i=0; i<m_size; ++i )
			std::swap(m_data[i], oldData[i]);

		if( oldCapacity > n )
			free(oldData);
    }
}
