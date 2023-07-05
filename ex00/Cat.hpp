#pragma once

#include "Animal.hpp"

class Cat: public Animal
{
private:
	std::string	type;

public:
//con- and destructors
	Cat();
	Cat(Cat &C);
	Cat	&operator = (Cat &C);
	~Cat();

//getter
	std::string	getType(void) const;
//setter
	void	setType(std::string type);

//member-function
	virtual void	makeSound() const;
};