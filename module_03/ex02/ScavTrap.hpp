#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"


class ScavTrap: public ClapTrap
{
public:
//con- and destructors
	ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(ScavTrap &C);
	ScavTrap	&operator = (ScavTrap &C);
	~ScavTrap();

//member-functions
	void	attack(const std::string& target);
	void	guardGate();
};

#endif