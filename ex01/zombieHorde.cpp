#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*horde = new Zombie[N];

	for (int x = 0; x < N; x++)
		horde[x].set_name(name);
	return (horde);
}