#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;
	public:
	//constructor
		HumanB(std::string name);
	//setter
		void	setWeapon(Weapon &weapon);
	//member-function
		void	attack();
};

#endif