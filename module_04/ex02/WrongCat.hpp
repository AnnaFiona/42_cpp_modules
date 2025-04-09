#pragma once

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
private:
	std::string	type;

public:
//con- and destructors
	WrongCat();
	WrongCat(WrongCat &C);
	WrongCat	&operator = (WrongCat &C);
	~WrongCat();

//getter
	std::string	getType(void) const;
//setter
	void	setType(std::string type);

//member-function
	void	makeSound() const;
};