#include "HumanA.hpp"

//constructor
HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
	this->name = name;
}

//setter
void	HumanA::setWeapon(Weapon &weapon)
{
	this->weapon = weapon;
}

//member-function
void	HumanA::attack()
{
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << this->weapon.getType() << std::endl;
}