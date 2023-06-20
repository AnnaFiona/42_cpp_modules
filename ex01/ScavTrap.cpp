#include "ScavTrap.hpp"

//con- and destructors
ScavTrap::ScavTrap()
{
	this->_Name = "ScavTrap";
	this->_HitPoints = 100;
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

//getters
std::string	ScavTrap::get_Name() const
{
	return (this->_Name);
}
int	ScavTrap::get_HitPoints() const
{
	return (this->_HitPoints);
}
int	ScavTrap::get_EnergyPoints() const
{
	return (this->_EnergyPoints);
}
int	ScavTrap::get_AttackDamage() const
{
	return (this->_AttackDamage);
}
//setters
void	ScavTrap::set_Name(const std::string name)
{
	ClapTrap::set_Name(name);
	this->_Name = name;
}
void	ScavTrap::set_HitPoints(const unsigned int hit_points)
{
	ClapTrap::set_HitPoints(hit_points);
	this->_HitPoints = hit_points;
}
void	ScavTrap::set_EnergyPoints(const unsigned int energy_points)
{
	ClapTrap::set_EnergyPoints(energy_points);
	this->_EnergyPoints = energy_points;
}
void	ScavTrap::set_AttackDamage(const unsigned int attack_damage)
{
	ClapTrap::set_AttackDamage(attack_damage);
	this->_AttackDamage = attack_damage;
}

//mmber-function
void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_Name << " is now in Gate keeper mode" << std::endl;
}