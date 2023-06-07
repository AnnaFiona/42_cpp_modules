#include <iostream>

int main(int argc, char *argv[])
{
	int		y = 1;
	int		x = 0;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (y < argc)
	{
		x = 0;
		while (argv[y][x])
		{
			std::cout << (char)toupper(argv[y][x]);
			x++;
		}
		y++;
	}
	std::cout << std::endl;
	return (0);
}