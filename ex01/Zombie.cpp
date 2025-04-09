#include "Zombie.hpp"

//default-constructor
Zombie::Zombie()
{
	Zombie::name = "Zombie";
}

//copy-constructor
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

//setter
void	Zombie::set_name(std::string name)
{
	this->name = name;
}

//member-function
void	Zombie::announce( void )
{
	std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
