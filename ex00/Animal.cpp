#include "Animal.hpp"

//con- and destrucors
Animal::Animal()
{
	this->type = "Animal";

	std::cout << "default-constructor of Animal '" << this->type << "' called" << std::endl;
}
Animal::Animal(const std::string type)
{
	this->type = type;
	std::cout << "name(?)-constructor of Animal '" << this->type << "' called" << std::endl;
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