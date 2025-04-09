#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{
	std::string	name;

	public:

	Zombie(std::string name);	
	~Zombie(void);

	void	announce( void );
};

//newZombie.cpp
Zombie*	newZombie( std::string name );
//randomChump.cpp
void	randomChump( std::string name );

#endif