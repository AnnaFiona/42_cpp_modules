#include "tests.hpp"

void	ok()
{
	std::cout << "\033[0;92m OK\033[0m";
}
void	fail()
{
	std::cout << "\033[0;91m FAIL\033[0m";
}

void	compare(const char *test, const int my_output, const int right_output, const char last)
{
	if (test != NULL)
		std::cout << test;
	if (my_output == right_output)
		std::cout << "\033[0;92m OK\033[0m";
	else
	{
		std::cout << "\033[0;91m FAIL\033[0m" << std::endl;
		std::cout << "My output:	" << my_output << std::endl;
		std::cout << "Right output:	" << right_output << std::endl;
	}
	if (last == 'y')
		std::cout << std::endl;
}
void	compare(const char *test, const std::string my_output, const std::string right_output, const char last)
{
	if (test != NULL)
		std::cout << test;
	if (my_output == right_output)
		std::cout << "\033[0;92m OK\033[0m";
	else
	{
		std::cout << "\033[0;91m FAIL\033[0m" << std::endl;
		std::cout << "My output:	" << my_output << std::endl;
		std::cout << "Right output:	" << right_output << std::endl;
	}
	if (last == 'y')
		std::cout << std::endl;
}
void	compare(std::streambuf *filebuf,std::streambuf *coutbuf , \
				const char *test, const int my_output, const int right_output, const char last)
{
	std::cout.rdbuf(coutbuf);
	if (test != NULL)
		std::cout << test;
	if (my_output == right_output)
		std::cout << "\033[0;92m OK\033[0m";
	else
	{
		std::cout << "\033[0;91m FAIL\033[0m" << std::endl;
		std::cout << "My output:	" << my_output << std::endl;
		std::cout << "Right output:	" << right_output << std::endl;
	}
	if (last == 'y')
		std::cout << std::endl;
	std::cout.rdbuf(filebuf);
}
void	compare(std::streambuf *filebuf,std::streambuf *coutbuf , \
				const char *test, const std::string my_output, const std::string right_output, const char last)
{
	std::cout.rdbuf(coutbuf);
	if (test != NULL)
		std::cout << test;
	if (my_output == right_output)
		std::cout << "\033[0;92m OK\033[0m";
	else
	{
		std::cout << "\033[0;91m FAIL\033[0m" << std::endl;
		std::cout << "My output:	" << my_output << std::endl;
		std::cout << "Right output:	" << right_output << std::endl;
	}
	if (last == 'y')
		std::cout << std::endl;
	std::cout.rdbuf(filebuf);
}

std::string	get_file_content(char *right_output_file)
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
		getline(infile, buf);
		right_output += buf + "\n";
	}
	return (right_output);
}

int main()
{
	animal_tests();
	return (0);
}