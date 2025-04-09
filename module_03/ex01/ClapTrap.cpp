#include "ClapTrap.hpp"

//con- and destrucors
ClapTrap::ClapTrap()
{
	this->_Name = "ClapTrap";
	this->_HitPoints = 10;
	this->_EnergyPoints = 10;
	this->_AttackDamage = 0;
	std::cout << "default-constructor of ClapTrap '" << this->_Name << "' called" << std::endl;
}
ClapTrap::ClapTrap(const std::string name)
{
	this->_Name = name;
	this->_HitPoints = 10;
	this->_EnergyPoints = 10;
	this->_AttackDamage = 0;
	std::cout << "name(?)-constructor of ClapTrap '" << this->_Name << "' called" << std::endl;
}
ClapTrap::ClapTrap(ClapTrap &C)
{
	*(this) = C;
	std::cout << "copy-constructor of ClapTrap '" << this->_Name << "' called" << std::endl;
}
ClapTrap	&ClapTrap::operator = (ClapTrap &C)
{
	this->_Name = C._Name;
	this->_HitPoints = C._HitPoints;
	this->_EnergyPoints = C._EnergyPoints;
	this->_AttackDamage = C._AttackDamage;
	std::cout << "copy assignment operator of ClapTrap '" << this->_Name << "' called" << std::endl;
	return (*this);
}
ClapTrap::~ClapTrap()
{
	std::cout << "destructor of ClapTrap '" << this->_Name << "' called" << std::endl;
}

//getters
std::string	ClapTrap::get_Name() const
{
	return (this->_Name);
}
int	ClapTrap::get_HitPoints() const
{
	return (this->_HitPoints);
}
int	ClapTrap::get_EnergyPoints() const
{
	return (this->_EnergyPoints);
}
int	ClapTrap::get_AttackDamage() const
{
	return (this->_AttackDamage);
}
//setters
void	ClapTrap::set_Name(const std::string name)
{
	this->_Name = name;
}
void	ClapTrap::set_HitPoints(const unsigned int hit_points)
{
	this->_HitPoints = hit_points;
}
void	ClapTrap::set_EnergyPoints(const unsigned int energy_points)
{
	this->_EnergyPoints = energy_points;
}
void	ClapTrap::set_AttackDamage(const unsigned int attack_damage)
{
	this->_AttackDamage = attack_damage;
}

//member-functions
void	ClapTrap::attack(const std::string& target)
{
	if (this->_HitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_Name << " can't do anything. It is dead." << std::endl;
		return;
	}
	if (this->_EnergyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_Name << " is out of breath. It can't attack." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_Name << " attacks " << target \
			<< ", cousing " << this->_AttackDamage << " points of damage!" << std::endl;
	this->_EnergyPoints--;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_HitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_Name \
				<< " can't take further damage. It is already dead." << std::endl;
		return;
	}
	this->_HitPoints -= amount;
	std::cout << "ClapTrap " << this->_Name << " takes " << amount \
			<< " points of damage! It has now a total of " \
			<< this->_HitPoints << " Hit Points" << std::endl;
	if (this->_HitPoints <= 0)
		std::cout << "ClapTrap " << this->_Name << " took too much damage. It died." << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_HitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_Name << " can't do anything. It is dead." << std::endl;
		return;
	}
	if (this->_EnergyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_Name \
				<< " is out of breath. It can't repair itself." << std::endl;
		return;
	}
	this->_HitPoints += amount;
	std::cout << "ClapTrap " << this->_Name << " gains " << amount \
			<< " Hit Points. It has now a total of " << this->_HitPoints \
			<< " Hit Points" << std::endl;
	this->_EnergyPoints--;
}