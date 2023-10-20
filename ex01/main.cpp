#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data		*ptr = new Data;
	Data		*p = NULL;
	uintptr_t	raw;

	raw = Serializer::serialize(ptr);
	p = Serializer::deserialize(raw);

	std::cout << "p:	" << p << std::endl;
	std::cout << "ptr:	" << ptr << std::endl;

	delete ptr;
}