#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>

void	check(const int test_nr, std::string input, const std::string expected_output)
{
	std::string	red_bold("\033[1;31m");
	std::string	yellow("\033[0;33m");
	std::string white("\033[0m");
	std::string green("\033[0;32m");


	std::stringstream	stream;
	std::streambuf		*buf(std::cout.rdbuf());
	std::string			output;

	std::cout.rdbuf(stream.rdbuf());
	ScalarConverter::convert(input);
	std::cout.rdbuf(buf);

	output = stream.str();
	if (output == expected_output)
		std::cout << green << test_nr << ": OK" << white << std::endl;
	else
	{
		std::cout << red_bold << test_nr << ": FAIL" << white << std::endl;
		std::cout << yellow << "expected output:" << white << std::endl << expected_output;
		std::cout << yellow << "function output:" << white << std::endl << output << std::endl;
	}
}

int	main()
{
	check(1, "0", "int:	0\nchar:	not displayable\nfloat:	0.0f\ndouble:	0.0\n");
}