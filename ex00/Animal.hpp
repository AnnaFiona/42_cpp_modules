#pragma once

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string type;

public:
//con- and destructors
	Animal();
	Animal(const std::string type);
	Animal(Animal &C);
	Animal	&operator = (Animal &C);
	~Animal();

//getter
	std::string	getType(void) const;
//setter
	void	setType(std::string type);
};