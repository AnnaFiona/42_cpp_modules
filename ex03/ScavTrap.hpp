#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"


class ScavTrap: virtual public ClapTrap
{
public:
//con- and destructors
	ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &C);
	ScavTrap	&operator = (ScavTrap C);
	~ScavTrap();

//member-function
	void	guardGate();
};

#endif