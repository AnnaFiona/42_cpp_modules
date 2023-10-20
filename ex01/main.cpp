#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data		*ptr = new Data;
	uintptr_t	raw;

	raw = Serializer::serialize(ptr);
//	ptr = Serializer::deserialize(raw);

	std::cout << "raw:	" << Serializer::deserialize(raw) << std::endl;
	std::cout << "ptr:	" << &ptr << std::endl;

	delete ptr;
}