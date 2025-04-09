#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
private:
	std::string	_Name;
	int			_HitPoints;
	int			_EnergyPoints;
	int			_AttackDamage;

public:
//con- and destructors
	ClapTrap();
	ClapTrap(const std::string name);
	ClapTrap(ClapTrap &C);
	ClapTrap	&operator = (ClapTrap &C);
	~ClapTrap();

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

//member-functions
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif