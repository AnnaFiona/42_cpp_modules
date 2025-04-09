#include "Cat.hpp"

//con- and destrucors
Cat::Cat()
{
	this->type = "Cat";
	brain = new Brain();
	std::cout << "default-constructor of Cat '" << this->type << "' called" << std::endl;
}
Cat::Cat(Cat &C) : Animal (C)
{
	this->brain = new Brain();
	*(this) = C;
	std::cout << "copy-constructor of Cat '" << this->type << "' called" << std::endl;
}
Cat	&Cat::operator = (Cat &C)
{
	this->type = C.type;
	delete this->brain;
	this->brain = new Brain();
	for (int x = 0; x < 100; x++)
		this->brain->ideas[x] = C.brain->ideas[x];
	
	std::cout << "copy assignment operator of Cat '" << this->type << "' called" << std::endl;
	return (*this);
}
Cat::~Cat()
{
	delete brain;
	std::cout << "destructor of Cat '" << this->type << "' called" << std::endl;
}

//getter
std::string	Cat::getType(void) const
{
	return (this->type);
}
std::string	Cat::getIdea(const int x) const
{
	if (x >= 100 || x < 0)
	{
		std::cerr << "Error: Cat::getIdea: the integer must be (int >= 100 || int < 0)" << std::endl;
		std::exit (1);
	}
	return (this->brain->ideas[x]);
}
Brain *Cat::getBrain(void) const
{
	return (this->brain);
}
//setter
void	Cat::setType(const std::string type)
{
	this->type = type;
}
void	Cat::setIdea(const std::string idea, const int x)
{
	if (x >= 100 || x < 0)
	{
		std::cerr << "Error: Cat::getIdea: the integer must be (int >= 100 || int < 0)" << std::endl;
		std::exit (1);
	}
	this->brain->ideas[x] = idea;
}
void	Cat::setBrain(Brain *brain)
{
	delete this->brain;
	this->brain = brain;
}

//member-function
void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}