#include "ScavTrap.hpp"

//con- and destructors
ScavTrap::ScavTrap() : ClapTrap ()
{
	this->_Name = "ScavTrap";
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	std::cout << "default-constructor of ScavTrap '" << this->_Name << "' called" << std::endl;
}
ScavTrap::ScavTrap(const std::string name) : ClapTrap (name)
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	std::cout << "name(?)-constructor of ScavTrap '" << this->_Name << "' called" << std::endl;
}
ScavTrap::ScavTrap(ScavTrap &C) : ClapTrap (C)
{
	std::cout << "copy-constructor of ScavTrap '" << this->_Name << "' called" << std::endl;
}
ScavTrap	&ScavTrap::operator = (ScavTrap &C)
{
	this->_Name = C._Name;
	this->_HitPoints = C._HitPoints;
	this->_EnergyPoints = C._EnergyPoints;
	this->_AttackDamage = C._AttackDamage;
	std::cout << "copy assignment operator of ScavTrap '" << this->_Name << "' called" << std::endl;
	return (*this);
}
ScavTrap::~ScavTrap()
{
	std::cout << "destructor of ScavTrap '" << this->_Name << "' called" << std::endl;
}

//member-functions
void	ScavTrap::attack(const std::string& target)
{
	if (this->_HitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_Name << " can't do anything. It is dead." << std::endl;
		return;
	}
	if (this->_EnergyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_Name << " is out of breath. It can't attack." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->_Name << " attacks " << target \
			<< ", cousing " << this->_AttackDamage << " points of damage!" << std::endl;
	this->_EnergyPoints--;
}
void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_Name << " is now in Gate keeper mode" << std::endl;
}