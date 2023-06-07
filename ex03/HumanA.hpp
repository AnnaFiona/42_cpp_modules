#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA
{
	private:
		std::string	name;
		Weapon		&weapon;
	public:
	//constructor
		HumanA(std::string name, Weapon &weapon);
	//setter
		void	setWeapon(Weapon &weapon);
	//member-function
		void	attack();
};


#endif