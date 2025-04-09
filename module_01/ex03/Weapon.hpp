#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	private:
		std::string type;
	
	public:
	//constructor
		Weapon(std::string type);
		
	//getter
		const std::string	&getType();
	//setter
		void	setType(std::string type);
};


#endif