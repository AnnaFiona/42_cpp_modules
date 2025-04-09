#include "Brain.hpp"

//con- and destrucors
Brain::Brain()
{
	std::cout << "default-constructor of Brain called" << std::endl;
}
Brain::Brain(Brain &C)
{
	*(this) = C;
	std::cout << "copy-constructor of Brain called" << std::endl;
}
Brain	&Brain::operator = (Brain &C)
{
	for (int x = 0; x < 100; x++)
		this->ideas[x] = C.ideas[x];
	std::cout << "copy assignment operator of Brain called" << std::endl;
	return (*this);
}
Brain::~Brain()
{
	std::cout << "destructor of Brain called" << std::endl;
}
