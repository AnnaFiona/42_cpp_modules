#include "ScavTrap.hpp"

//con- and destructors
ScavTrap::ScavTrap()
{
	this->_Name = "ScavTrap";
	std::cout << "HitPoints: " << this->_HitPoints << std::endl;
	this->_HitPoints = 100;
	std::cout << "HitPoints: " << this->_HitPoints << std::endl;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	std::cout << "default-constructor of ScavTrap '" << this->_Name << "' called" << std::endl;
}
ScavTrap::ScavTrap(const std::string name) : ClapTrap (name)
{
	this->_Name = name;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	std::cout << "name(?)-constructor of ScavTrap '" << this->_Name << "' called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &C) : ClapTrap (C)
{
	this->_Name = C._Name;
	this->_HitPoints = C._HitPoints;
	this->_EnergyPoints = C._EnergyPoints;
	this->_AttackDamage = C._AttackDamage;
	std::cout << "copy-constructor of ScavTrap '" << this->_Name << "' called" << std::endl;
}
ScavTrap	&ScavTrap::operator = (ScavTrap C)
{
	std::cout << "copy assignment operator of ScavTrap '" << this->_Name << "' called" << std::endl;
	std::swap(this->_Name, C._Name);
	std::swap(this->_HitPoints, C._HitPoints);
	std::swap(this->_EnergyPoints, C._EnergyPoints);
	std::swap(this->_AttackDamage, C._AttackDamage);
	return (*this);
}
ScavTrap::~ScavTrap()
{
	std::cout << "destructor of ScavTrap '" << this->_Name << "' called" << std::endl;
}

//member-function
void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_Name << " is now in Gate keeper mode" << std::endl;
}