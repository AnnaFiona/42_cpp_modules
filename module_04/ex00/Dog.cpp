#include "Dog.hpp"

//con- and destrucors
Dog::Dog()
{
	this->type = "Dog";
	std::cout << "default-constructor of Dog '" << this->type << "' called" << std::endl;
}
Dog::Dog(Dog &C) : Animal (C)
{
	*(this) = C;
	std::cout << "copy-constructor of Dog '" << this->type << "' called" << std::endl;
}
Dog	&Dog::operator = (Dog &C)
{
	this->type = C.type;
	std::cout << "copy assignment operator of Dog '" << this->type << "' called" << std::endl;
	return (*this);
}
Dog::~Dog()
{
	std::cout << "destructor of Dog '" << this->type << "' called" << std::endl;
}

//getter
std::string	Dog::getType(void) const
{
	return (this->type);
}
//setter
void	Dog::setType(std::string type)
{
	this->type = type;
}

//member-function
void	Dog::makeSound() const
{
	std::cout << "Bark" << std::endl;
}