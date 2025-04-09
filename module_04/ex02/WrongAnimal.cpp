#include "WrongAnimal.hpp"

//con- and destrucors
WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	std::cout << "default-constructor of WrongAnimal '" << this->type << "' called" << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal &C)
{
	*(this) = C;
	std::cout << "copy-constructor of WrongAnimal '" << this->type << "' called" << std::endl;
}
WrongAnimal	&WrongAnimal::operator = (WrongAnimal &C)
{
	this->type = C.type;
	std::cout << "copy assignment operator of WrongAnimal '" << this->type << "' called" << std::endl;
	return (*this);
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "destructor of WrongAnimal '" << this->type << "' called" << std::endl;
}

//getter
std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}
//setter
void	WrongAnimal::setType(std::string type)
{
	this->type = type;
}

//member-function
void	WrongAnimal::makeSound() const
{
	std::cout << "..." << std::endl;
}