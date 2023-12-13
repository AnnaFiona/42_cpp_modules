#include "PmergeMe.hpp"

bool	is_unsigned_int(const std::string str)
{
	std::stringstream	stream;
	std::string			cntrl_str;
	unsigned int		u;

	stream << str;
	stream >> u;
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
		if (!is_pos_int())
			//throw error

	}
}

int main(const int argc, const char *argv[])
{
	if (argc < 2)
		//error message
	try {
		check_array(argv); //throws exception
		PmergeMe(argv); //throws exception
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}