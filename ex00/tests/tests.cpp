#include "tests.hpp"

void	ok(std::ofstream &file)
{
	file << " OK";
}
void	fail(std::ofstream &file)
{
	file << " FAIL";
}

void	compare(std::ofstream &file, const char *test, int my_output, int right_output, char last)
{
	if (test != NULL)
		file << test;
	if (my_output == right_output)
		file << " OK";
	else
	{
		file << " FAIL" << std::endl;
		file << "My output:	" << my_output << std::endl;
		file << "Right output:	" << right_output << std::endl;
	}
	if (last == 'y')
		file << std::endl;
}

int main()
{
	std::ofstream	file;

	file.open("test_result.txt", std::ofstream::out);
	if (!file.is_open())
	{
		std::cout << "Error: couldn't open file" << std::endl;
		return (1);
	}
	clap_trap_tests(file);
	file.close();

	return (0);
}