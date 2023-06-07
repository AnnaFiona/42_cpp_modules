#include "Weapon.hpp"

//constructor
Weapon::Weapon(std::string type)
{
	this->type = type;
}

//getter
const std::string	&Weapon::getType()
{
	return (this->type);
}
//setter
void	Weapon::setType(std::string type)
{
	this->type = type;
}