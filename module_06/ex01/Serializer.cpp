#include "Serializer.hpp"

//con- and destructors
Serializer::Serializer() {}
Serializer::Serializer(const Serializer& S)
{
	(*this) = S;
}
Serializer& Serializer::operator = (const Serializer& S)
{
	(void)(S);
	return (*this);
}
Serializer::~Serializer() {}

//methods
uintptr_t   Serializer::serialize(Data* ptr)
{
    uintptr_t   raw = reinterpret_cast<uintptr_t>(ptr);
    return (raw);
}
Data*       Serializer::deserialize(uintptr_t raw)
{
    Data    *ptr = reinterpret_cast<Data*>(raw);
    return (ptr);
}