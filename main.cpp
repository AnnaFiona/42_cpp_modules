#include "Zombie.hpp"

int	main(void)
{
	Zombie	zom1("Zombie");
	Zombie	*zom2;

	zom1.announce();
	zom2 = newZombie("newZombie");
	zom2->announce();
	delete zom2;
	randomChump("randomChump");

	return (0);
}