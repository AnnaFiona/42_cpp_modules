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
	if (this->weapon == NULL)
	{
		std::cerr << "Error: " << this->name << " cannot attack: Weapon not set" << std::endl;
		return;
	}
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << this->weapon->getType() << std::endl;
}