#pragma once

//#include <cstdint>
#include "Data.hpp"
#include "stdint.h"

class Serializer
{
private:
//con- and destructors
	Serializer();
	Serializer(const Serializer& S);
	Serializer& operator = (const Serializer& S);
	~Serializer();

public:
//methods
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};