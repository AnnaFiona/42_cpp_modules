#include "PmergeMe.hpp"

bool	is_unsigned_int(const std::string str)
{
	std::stringstream	stream;
	std::string			cntrl_str;
	unsigned int		u;

	stream << str;
	stream >> u;
	stream.str("");
	stream.clear();
	stream << u;
	stream >> cntrl_str;
	if (cntrl_str != str)
		return (false);
	return (true);
}

void	check_array(const char **arr)
{
	for (unsigned int i = 1; arr[i]; i++)
	{
		if (!is_unsigned_int(arr[i]))
			throw (std::invalid_argument("only unsigned ints are accepted"));
	}
}

int main(const int argc, const char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Error: there needs to be at least one number" << std::endl;
		return 0;
	}
	try {
		check_array(argv); //throws exception
		PmergeMe(argc, argv); //throws exception (not my functions)
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}