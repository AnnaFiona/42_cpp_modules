#include "tests.hpp"

void	ok()
{
	std::cout << " OK";
}
void	fail()
{
	std::cout << " FAIL";
}

void	compare(const char *test, int my_output, int right_output, char last)
{
	if (test != NULL)
		std::cout << test;
	if (my_output == right_output)
		std::cout << " OK";
	else
	{
		std::cout << " FAIL" << std::endl;
		std::cout << "My output:	" << my_output << std::endl;
		std::cout << "Right output:	" << right_output << std::endl;
	}
	if (last == 'y')
		std::cout << std::endl;
}

std::string	get_right_output(char *right_output_file)
{
	std::ifstream	infile(right_output_file, std::ios::in);
	std::string		right_output;
	std::string		buf;

	if (!infile.is_open())
	{
		std::cerr << "Error: file '" << right_output_file << "' could not be opened" << std::endl;
		exit (1);
	}
	while (infile)
	{
		infile >> buf;
		right_output += buf + "\n";
	}
	return (right_output);
}

int main()
{
	animal_tests();
	return (0);
}