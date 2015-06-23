#pragma once

#include <sstream>
#include <stdexcept>


/// \brief Mixin for calculating the length (euclidian norm / distance) of a vector
// BONUS: Implement a mixin that calculates the length of a vector.
// Change the vector template to include this mixin.
//template <typename Base>
//class Speedometer : public Base {
//public:
//  void display() {
//    std::cout << this->speed() << std::endl;
//  }
//};


/// \brief Template class for (math) vectors of variable length and type.
/// Works with all basic number types.
template<unsigned int Size, typename Element = float>
class Vector
{
public:

	// As always use const wherever meaningful!
	// This time you have to think about meaningful function signatures yourself.
	// However, the given documentation should make it clearly what these signatures should look like.
	// If your signature does not work with the given test-code but you're absolutely sure
	// that your signature fits the requirements, just alter the test-code accordingly! ;)


	/// Constructor that initializes all elements with zero.
    Vector() {
        for ( unsigned int i = 0; i < Size; i++ ) {
            m_elements[ i ] = 0;
        }
    }

	/// Constructor that copies the vector
    Vector(Vector<Size, Element> const& v) {
        for ( unsigned int i = 0; i < Size; i++ ) {
            m_elements[ i ] = v[ i ];
        }
    }

	/// Constructor that copies a vector of an arbitrary type with the same size.
	/// The type must be convertible by a static_cast to Element.
    template<typename T>
    Vector(Vector<Size, T> const& v) {
        for ( unsigned int i = 0; i < Size; i++ ) {
            m_elements[ i ] = v[ i ];
        }
    }

	/// \brief Constructor that initializes the vector from a string.
	/// The string should contain values, separated by spaces. Uses stringstream for parsing.
	/// Will set all other elements to zero.
    Vector(std::string const valueString) {
        std::stringstream valueStream(valueString);
        unsigned int i = 0;
        while ( valueStream >> m_elements[ i++ ]) {
            if ( i > Size )
                throw std::invalid_argument("Argument count doesn't match Length.");
        }
        i--;
        while ( i < Size ) {
            m_elements[ i++ ] = 0;
        }
    }

	/// \brief Returns a string representation of the vector.
    std::string toString() const {
        std::stringstream output;
        for ( unsigned int i = 0; i < Size; i++ ) {
            output << ( i > 0 ? " " : "") << m_elements[ i ];
        }
        return output.str();
    }

    operator std::string() {
        return this->toString();
    }

	/// \brief Read access to an element.
	/// Checks for errors in debug mode - perform an error report of your choice
    Element operator[](unsigned int const pos) const {
    #ifdef DEBUG
        if ( pos >= SIZE ) {
            throw std::out_of_range( "Index out of bounds." );
        }
    #endif
        return m_elements[ pos ];
    }

	/// \brief Write access to an element.
	/// Checks for errors in debug mode - perform an error report of your choice
    Element& operator[](unsigned int const pos) {
    #ifdef DEBUG
        if ( pos >= SIZE ) {
            throw std::out_of_range( "Index out of bounds." );
        }
    #endif
        return m_elements[ pos ];
    }

	/// \brief Adds to vectors of the same size and type element-wise.
    Vector<Size, Element> operator+(Vector<Size, Element> const& v) {
        Vector<Size, Element> res;
        for ( unsigned int i = 0; i < Size; i++ ) {
            res[ i ] = m_elements[ i ] + v[ i ];
        }
        return res;
    }

	/// \brief Simple template programming trick to make size accessible from outside.
	enum MetaInfo
	{
		SIZE = Size
	};

private:
	/// Intern data representation.
    Element m_elements[Size];
};
