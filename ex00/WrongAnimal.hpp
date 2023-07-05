#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
//con- and destructors
	WrongAnimal();
	WrongAnimal(WrongAnimal &C);
	WrongAnimal	&operator = (WrongAnimal &C);
	~WrongAnimal();

//getter
	std::string	getType(void) const;
//setter
	void	setType(std::string type);

//member-function
	void	makeSound() const;
};