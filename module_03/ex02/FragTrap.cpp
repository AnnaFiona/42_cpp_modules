#include "FragTrap.hpp"

//con- and destructors
FragTrap::FragTrap() : ClapTrap ()
{
	this->_Name = "FragTrap";
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	std::cout << "default-constructor of FragTrap '" << this->_Name << "' called" << std::endl;
}
FragTrap::FragTrap(const std::string name) : ClapTrap (name)
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	std::cout << "name(?)-constructor of FragTrap '" << this->_Name << "' called" << std::endl;
}
FragTrap::FragTrap(FragTrap &C) : ClapTrap (C)
{
	std::cout << "copy-constructor of FragTrap '" << this->_Name << "' called" << std::endl;
}
FragTrap	&FragTrap::operator = (FragTrap &C)
{
	this->_Name = C._Name;
	this->_HitPoints = C._HitPoints;
	this->_EnergyPoints = C._EnergyPoints;
	this->_AttackDamage = C._AttackDamage;
	std::cout << "copy assignment operator of FragTrap '" << this->_Name << "' called" << std::endl;
	return (*this);
}
FragTrap::~FragTrap()
{
	std::cout << "destructor of FragTrap '" << this->_Name << "' called" << std::endl;
}

//member-function
void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_Name << " is positively requesting a high fives." << std::endl;
}