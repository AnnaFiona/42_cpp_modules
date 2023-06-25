#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"


class DiamondTrap:public FragTrap, public ScavTrap
{
private:
	std::string _Name;
public:
//con- and destructors
	DiamondTrap();
	DiamondTrap(const std::string name);
	DiamondTrap(const DiamondTrap &C);
	DiamondTrap	&operator = (DiamondTrap C);
	~DiamondTrap();

//getters
	std::string	get_Name() const;
	std::string	get_Name_clap() const;
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
void	whoAmI();

};

#endif

