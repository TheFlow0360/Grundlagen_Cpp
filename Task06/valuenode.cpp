#include "valuenode.h"

#include <unordered_map>

Node* Value::clone() const
{
	// Create a new instance with the same type and data. As you can see we
	// need to know the type ´Value´ that is why we cannot implement it
	// elsewhere.
    return new Value( *this );
}

int Value::evaluate(const VariableMap* _varMap) const
{
    if ( _varMap->find( m_val ) != _varMap->end() ) {
        // found valid mapping
        return _varMap->at( m_val );
    } else {
        return atoi( m_val.c_str() ); // TODO direct conversion
    }
}

std::string Value::toString() const
{
    return m_val;
}

Value::Value(const Value& v)
{
    m_val = v.m_val;
}

Value &Value::operator =(const Value& v)
{
    // TODO
    return *this;
}
