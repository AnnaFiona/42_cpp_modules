#include "HumanB.hpp"

//constructor
HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

//setter
void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

//member-function
void	HumanB::attack()
{
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << this->weapon->getType() << std::endl;
}