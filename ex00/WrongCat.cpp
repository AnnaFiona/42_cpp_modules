#include "WrongCat.hpp"

//con- and destrucors
WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "default-constructor of WrongCat '" << this->type << "' called" << std::endl;
}
WrongCat::WrongCat(WrongCat &C) : WrongAnimal (C)
{
	*(this) = C;
	std::cout << "copy-constructor of WrongCat '" << this->type << "' called" << std::endl;
}
WrongCat	&WrongCat::operator = (WrongCat &C)
{
	this->type = C.type;
	std::cout << "copy assignment operator of WrongCat '" << this->type << "' called" << std::endl;
	return (*this);
}
WrongCat::~WrongCat()
{
	std::cout << "destructor of WrongCat '" << this->type << "' called" << std::endl;
}

//getter
std::string	WrongCat::getType(void) const
{
	return (this->type);
}
//setter
void	WrongCat::setType(std::string type)
{
	this->type = type;
}

//member-function
void	WrongCat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}