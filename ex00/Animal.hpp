#pragma once

#include <iostream>
#include <string>

class Animal
{
private:
	std::string type;

public:
//con- and destructors
	Animal();
	Animal(const std::string type);
	Animal(Animal &C);
	Animal	&operator = (Animal &C);
	~Animal();
};