#include "Cat.hpp"

//con- and destrucors
Cat::Cat()
{
	this->type = "Cat";
	std::cout << "default-constructor of Cat '" << this->type << "' called" << std::endl;
}
Cat::Cat(Cat &C) : Animal (C)
{
	*(this) = C;
	std::cout << "copy-constructor of Cat '" << this->type << "' called" << std::endl;
}
Cat	&Cat::operator = (Cat &C)
{
	this->type = C.type;
	std::cout << "copy assignment operator of Cat '" << this->type << "' called" << std::endl;
	return (*this);
}
Cat::~Cat()
{
	std::cout << "destructor of Cat '" << this->type << "' called" << std::endl;
}

//getter
std::string	Cat::getType(void) const
{
	return (this->type);
}
//setter
void	Cat::setType(std::string type)
{
	this->type = type;
}

//member-function
void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}