#include "DiamondTrap.hpp"

//con- and destructors
DiamondTrap::DiamondTrap()
{
	this->_Name = "DiamondTrap";
	this->ClapTrap::_Name = "DiamondTrap_clap_name";
	this->FragTrap::_HitPoints = 100;
	this->ScavTrap::_EnergyPoints = 50;
	this->FragTrap::_AttackDamage = 30;
	std::cout << "default-constructor of DiamondTrap '" << this->_Name << "' called" << std::endl;
}
DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name), FragTrap (name), ScavTrap (name)
{
	this->_Name = name;
	this->ClapTrap::_Name = name + "_clap_name";
	this->FragTrap::_HitPoints = 100;
	this->ScavTrap::_EnergyPoints = 50;
	this->FragTrap::_AttackDamage = 30;
	std::cout << "_Name(?)-constructor of DiamondTrap '" << this->_Name << "' called" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &C) : ClapTrap(C), FragTrap (C), ScavTrap (C)
{
	this->_Name = C._Name;
	this->ClapTrap::_Name = C.ClapTrap::_Name;
	this->FragTrap::_HitPoints = C.FragTrap::_HitPoints;
	this->ScavTrap::_EnergyPoints = C.ScavTrap::_EnergyPoints;
	this->FragTrap::_AttackDamage = C.FragTrap::_AttackDamage;
	std::cout << "copy-constructor of DiamondTrap '" << this->_Name << "' called" << std::endl;
}
DiamondTrap	&DiamondTrap::operator = (DiamondTrap C)
{
	std::cout << "copy assignment operator of DiamondTrap '" << this->_Name << "' called" << std::endl;
	std::swap(this->_Name, C._Name);
	std::swap(this->ClapTrap::_Name, C.ClapTrap::_Name);
	std::swap(this->FragTrap::_HitPoints, C.FragTrap::_HitPoints);
	std::swap(this->ScavTrap::_EnergyPoints, C.ScavTrap::_EnergyPoints);
	std::swap(this->FragTrap::_AttackDamage, C.FragTrap::_AttackDamage);
	return (*this);
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "destructor of DiamondTrap '" << this->_Name << "' called" << std::endl;
}

//getters
std::string	DiamondTrap::get_Name() const
{
	return (this->_Name);
}
std::string	DiamondTrap::get_Name_clap() const
{
	return (this->ClapTrap::_Name);
}
int	DiamondTrap::get_HitPoints() const
{
	return (this->FragTrap::_HitPoints);
}
int	DiamondTrap::get_EnergyPoints() const
{
	return (this->ScavTrap::_EnergyPoints);
}
int	DiamondTrap::get_AttackDamage() const
{
	return (this->FragTrap::_AttackDamage);
}
//setters
void	DiamondTrap::set_Name(const std::string name)
{
	this->_Name = name;
	this->ClapTrap::_Name = name + "_clap_name";
}
void	DiamondTrap::set_HitPoints(const unsigned int hit_points)
{
	this->FragTrap::_HitPoints = hit_points;
}
void	DiamondTrap::set_EnergyPoints(const unsigned int energy_points)
{
	this->ScavTrap::_EnergyPoints = energy_points;
}
void	DiamondTrap::set_AttackDamage(const unsigned int attack_damage)
{
	this->FragTrap::_AttackDamage = attack_damage;
}

//member-functions
void	DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}
void	DiamondTrap::whoAmI()
{
	std::cout << this->_Name << ", " << this->ClapTrap::_Name << std::endl;
}