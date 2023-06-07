#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int		N = 3;

	horde = zombieHorde(N, "Student");
	for (int x = 0; x < N; x++)
		horde->announce();
	delete [] horde;
	return (0);
}