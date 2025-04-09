#include "Animal.hpp"

//con- and destrucors
Animal::Animal()
{
	this->type = "Animal";
	std::cout << "default-constructor of Animal '" << this->type << "' called" << std::endl;
}
Animal::Animal(Animal &C)
{
	*(this) = C;
	std::cout << "copy-constructor of Animal '" << this->type << "' called" << std::endl;
}
Animal	&Animal::operator = (Animal &C)
{
	this->type = C.type;
	std::cout << "copy assignment operator of Animal '" << this->type << "' called" << std::endl;
	return (*this);
}
Animal::~Animal()
{
	std::cout << "destructor of Animal '" << this->type << "' called" << std::endl;
}

//getter
std::string	Animal::getType(void) const
{
	return (this->type);
}
//setter
void	Animal::setType(std::string type)
{
	this->type = type;
}

//member-function
void	Animal::makeSound() const
{
	std::cout << "..." << std::endl;
}