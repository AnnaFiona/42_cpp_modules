#pragma once

#include "Animal.hpp"

class Dog: public Animal
{
private:
	std::string	type;

public:
//con- and destructors
	Dog();
	Dog(Dog &C);
	Dog	&operator = (Dog &C);
	~Dog();

//getter
	std::string	getType(void) const;
//setter
	void	setType(std::string type);

//member-function
	virtual void	makeSound() const;
};