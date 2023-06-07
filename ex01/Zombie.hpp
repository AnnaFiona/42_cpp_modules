#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{
	std::string	name;

	public:

	Zombie();
	Zombie(std::string name);	
	~Zombie();

	//setter
	void	set_name(std::string name);

	//member-function
	void	announce( void );
};

//zombieHorde.cpp
Zombie* zombieHorde( int N, std::string name );

#endif