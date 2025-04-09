#include "Zombie.hpp"

//default-constructor
Zombie::Zombie(std::string name)
{
	
	Zombie::name = name;
}
//destructor
Zombie::~Zombie(void)
{
	std::cout << "Zombie '" << this->name << "' is not needed anymore" << std::endl;
	this->name = "";
}

//member-function
void	Zombie::announce( void )
{
	std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
