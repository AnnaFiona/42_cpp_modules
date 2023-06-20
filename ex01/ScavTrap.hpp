#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"


class ScavTrap: public ClapTrap
{
private:
	std::string	_Name;
	int			_HitPoints;
	int			_EnergyPoints;
	int			_AttackDamage;

public:
//con- and destructors
	ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &C);
	ScavTrap	&operator = (ScavTrap C);
	~ScavTrap();

//getters
	std::string	get_Name() const;
	int			get_HitPoints() const;
	int			get_EnergyPoints() const;
	int			get_AttackDamage() const;
//setters
	void	set_Name(const std::string name);
	void	set_HitPoints(const unsigned int hit_points);
	void	set_EnergyPoints(const unsigned int energy_points);
	void	set_AttackDamage(const unsigned int attack_damage);

//member-function
	void	guardGate();
};

#endif