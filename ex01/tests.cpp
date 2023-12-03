#include "RPN.hpp"
#include <sstream>

void	RPN_print_error(const std::string input)
{
	try {
		RPN(input);
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

static void	check(const int test_nr, std::string input, const std::string expected_output)
{
	std::string	red_bold("\033[1;31m");
	std::string	yellow("\033[0;33m");
	std::string white("\033[0m");
	std::string green("\033[0;32m");


	std::stringstream	stream;
	std::streambuf		*buf(std::cout.rdbuf());
	std::string			output;

	std::cout.rdbuf(stream.rdbuf());
	RPN_print_error(input);
	std::cout.rdbuf(buf);

	output = stream.str();
	if (output == expected_output)
		std::cout << green << test_nr << ": OK" << white << std::endl;
	else
	{
		std::cout << red_bold << test_nr << ": FAIL: " << white << input << std::endl;
		std::cout << yellow << "expected output:" << white << std::endl << expected_output;
		std::cout << yellow << "function output:" << white << std::endl << output << std::endl;
	}
}



int main()
{
	check(1, "1", "1\n");
	check(1, "10", "Error: invalid argument\n");
	check(1, "-1", "Error: invalid argument\n");
	check(1, "0", "0\n");
	check(1, "1 2 3 4 5 6 7 8 9 + + + + + + + + ", "45\n");
	check(1, "  1 2 3 4 5 6 7 8 9 10 + + + + + + + + +", "Error: invalid argument\n");
	check(1, "1 1", "Error: operation is invalid2\n");
	check(1, "1 + 1", "Error: operation is invalid\n");
	check(1, "1 2 3 4 5 6 7 8 9 + + + + + + +", "Error: operation is invalid2\n");
	check(1, "1 2 3 4 5 a 7 8 9 + + + + + + +", "Error: invalid argument\n");
	check(1, "1 2 3 4 5 6a 7 8 9 + + + + + + +", "Error: invalid argument\n");
	check(1, "1 2 3 4 5 a6 7 8 9 + + + + + + +", "Error: invalid argument\n");
	check(1, "1 2 3 4 5 6 7 8 9 + + + a+ + + + +", "Error: invalid argument\n");
	check(1, "1 2 3 4 5 6 7 8 9 + + + + + + +a +", "Error: invalid argument\n");
	check(1, "1 2 3 4 5 6 7 8 9 + + + + + ++ + +", "Error: invalid argument\n");
	check(1, "1 2 3 4 5 6 7 8 9 + + + + + -+ + +", "Error: invalid argument\n");
	check(1, "1 2 3 4 5 6 7 8 9 + + + + + +- + +", "Error: invalid argument\n");
	check(1, "1 2 3 4 5 6 7 8 9 + + + + + + + + +", "Error: operation is invalid\n");
	check(1, "", "\n");
	check(1, "", "\n");
	check(1, "", "\n");
}