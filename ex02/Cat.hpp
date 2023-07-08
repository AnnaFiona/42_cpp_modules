#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <cstdlib> //allowed?

class Cat: public Animal
{
private:
	std::string	type;
	Brain		*brain;

public:
//con- and destructors
	Cat();
	Cat(Cat &C);
	Cat	&operator = (Cat &C);
	~Cat();

//getter
	std::string	getType(void) const;
	std::string	getIdea(const int x) const;
	Brain		*getBrain(void) const;
//setter
	void	setType(const std::string type);
	void	setIdea(const std::string idea, const int x);
	void	setBrain(Brain *brain);

//member-function
	void	makeSound() const;
};