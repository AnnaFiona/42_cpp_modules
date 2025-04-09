#include "Dog.hpp"

//con- and destrucors
Dog::Dog()
{
	this->type = "Dog";
	brain = new Brain();
	std::cout << "default-constructor of Dog '" << this->type << "' called" << std::endl;
}
Dog::Dog(Dog &C) : Animal (C)
{
	this->brain = new Brain();
	*(this) = C;
	std::cout << "copy-constructor of Dog '" << this->type << "' called" << std::endl;
}
Dog	&Dog::operator = (Dog &C)
{
	this->type = C.type;
	delete this->brain;
	this->brain = new Brain();
	for (int x = 0; x < 100; x++)
		this->brain->ideas[x] = C.brain->ideas[x];

	std::cout << "copy assignment operator of Dog '" << this->type << "' called" << std::endl;
	return (*this);
}
Dog::~Dog()
{
	delete brain;
	std::cout << "destructor of Dog '" << this->type << "' called" << std::endl;
}

//getter
std::string	Dog::getType(void) const
{
	return (this->type);
}
std::string	Dog::getIdea(const int x) const
{
	if (x >= 100 || x < 0)
	{
		std::cerr << "Error: Cat::getIdea: the integer must be (int >= 100 || int < 0)" << std::endl;
		std::exit (1);
	}
	return (this->brain->ideas[x]);
}
Brain *Dog::getBrain(void) const
{
	return (this->brain);
}
//setter
void	Dog::setType(const std::string type)
{
	this->type = type;
}
void	Dog::setIdea(const std::string idea, const int x)
{
	if (x >= 100 || x < 0)
	{
		std::cerr << "Error: Dog::getIdea: the integer must be (int >= 100 || int < 0)" << std::endl;
		std::exit (1);
	}
	this->brain->ideas[x] = idea;
}
void	Dog::setBrain(Brain *brain)
{
	delete this->brain;
	this->brain = brain;
}

//member-function
void	Dog::makeSound() const
{
	std::cout << "Bark" << std::endl;
}