#include "PmergeMe.hpp"

void	check_array(const char **arr)
{
	loop (arr)
		if (!is_pos_int())
			//throw error
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