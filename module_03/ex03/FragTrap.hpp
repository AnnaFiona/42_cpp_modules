#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"


class FragTrap: virtual public ClapTrap
{
public:
//con- and destructors
	FragTrap();
	FragTrap(const std::string name);
	FragTrap(FragTrap &C);
	FragTrap	&operator = (FragTrap &C);
	~FragTrap();

//member-function
	void	highFivesGuys(void);
};

#endif