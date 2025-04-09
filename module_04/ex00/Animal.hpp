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
	Animal(Animal &C);
	Animal	&operator = (Animal &C);
	virtual ~Animal();

//getter
	std::string	getType(void) const;
//setter
	void	setType(std::string type);

//member-function
	virtual void	makeSound() const;
};