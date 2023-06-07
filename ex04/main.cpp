#include "FtSed.hpp"

int	check_input(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: not the right amount of arguments" << std::endl;
		return (1);
	}
	if (argv[1][0] == '\0' || argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		std::cout << "Error: empty argument" << std::endl;
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (check_input(argc, argv) == 1)
		return (1);
	FtSed	sed(argv);
	
	sed.read_file();
	sed.replace();
	sed.write_to_file();
	return (0);
}