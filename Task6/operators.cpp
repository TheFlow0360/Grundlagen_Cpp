#include "operators.h"

#include <cassert>
#include <sstream>

// ************************************************************************* //
OpAdd::OpAdd(const OpAdd &)
{
    // TODO
}

OpAdd::~OpAdd()
{
    //delete[] m_children;
}

OpAdd::OpAdd(const Node& lhs, const Node& rhs)
{
    m_children[0] = lhs.clone();
    m_children[1] = rhs.clone();
}

OpAdd::OpAdd(Node* lhs, Node* rhs)
{
    m_children[0] = lhs;
    m_children[1] = rhs;
}

Node* OpAdd::clone() const
{
	// Cloning requires a deep copy. Otherwise multiple pointer would address
	// the same memory.
    return new OpAdd(m_children[0]->clone(), m_children[1]->clone());
}

int OpAdd::evaluate(const VariableMap *_varMap) const
{
    return m_children[0]->evaluate( _varMap ) + m_children[1]->evaluate( _varMap );
}

std::string OpAdd::toString() const
{
    std::stringstream stream;
    stream << "(" << m_children[0]->toString() << " + " << m_children[1]->toString() << ")";
    return stream.str();
}

OpAdd &OpAdd::operator =(const OpAdd &)
{
    // TODO
    return *this;
}

// ************************************************************************* //
OpMul::OpMul(const OpMul &)
{
    // TODO
}

OpMul::~OpMul()
{
    //delete[] m_children;
}

OpMul::OpMul(const Node& lhs, const Node& rhs)
{
    m_children[0] = lhs.clone();
    m_children[1] = rhs.clone();
}

OpMul::OpMul(Node* lhs, Node* rhs)
{
    m_children[0] = lhs;
    m_children[1] = rhs;
}

Node* OpMul::clone() const
{
	// Cloning requires a deep copy. Otherwise multiple pointer would address
	// the same memory.
    return new OpMul(m_children[0]->clone(), m_children[1]->clone());
}

int OpMul::evaluate(const VariableMap *_varMap) const
{
    return m_children[0]->evaluate( _varMap ) * m_children[1]->evaluate( _varMap );
}

std::string OpMul::toString() const
{
    std::stringstream stream;
    stream << "(" << m_children[0]->toString() << " * " << m_children[1]->toString() << ")";
    return stream.str();
}

OpMul &OpMul::operator =(const OpMul &)
{
    // TODO
    return *this;
}

// ************************************************************************* //
OpNegate::OpNegate(const OpNegate &)
{
    // TODO
}

OpNegate::~OpNegate()
{
    delete m_child;
}

OpNegate::OpNegate(const Node& lhs)
{
    m_child = lhs.clone();
}


OpNegate::OpNegate(Node* rhs)
{
    m_child = rhs;
}

Node* OpNegate::clone() const
{
	// Cloning requires a deep copy. Otherwise multiple pointer would address
	// the same memory.
    return new OpNegate(m_child->clone());
}

int OpNegate::evaluate(const VariableMap *_varMap) const
{
    return m_child->evaluate( _varMap ) * -1 ;
}

std::string OpNegate::toString() const
{
    std::stringstream stream;
    stream << "-" << m_child->toString();
    return stream.str();
}

OpNegate &OpNegate::operator =(const OpNegate &)
{
    // TODO
    return *this;
}
