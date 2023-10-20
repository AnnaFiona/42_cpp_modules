#include "ScalarConverter.hpp"

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

void	char_tests()
{
	std::cout << "//CHAR-TESTS//" << std::endl;
	check(1, "-1", "int:	-1\nchar:	not possible\nfloat:	-1.0f\ndouble:	-1.0\n");
	check(2, "0", "int:	0\nchar:	not displayable\nfloat:	0.0f\ndouble:	0.0\n");
	check(3, "1", "int:	1\nchar:	not displayable\nfloat:	1.0f\ndouble:	1.0\n");
	check(4, "31", "int:	31\nchar:	not displayable\nfloat:	31.0f\ndouble:	31.0\n");
	check(5, "32", "int:	32\nchar:	' '\nfloat:	32.0f\ndouble:	32.0\n");
	check(6, "126", "int:	126\nchar:	'~'\nfloat:	126.0f\ndouble:	126.0\n");
	check(7, "127", "int:	127\nchar:	not displayable\nfloat:	127.0f\ndouble:	127.0\n");
	check(8, "128", "int:	128\nchar:	not possible\nfloat:	128.0f\ndouble:	128.0\n");
	check(9, " ", "int:	32\nchar:	' '\nfloat:	32.0f\ndouble:	32.0\n");
	check(10,  "	", "int:	9\nchar:	not displayable\nfloat:	9.0f\ndouble:	9.0\n");
	check(11, "d", "int:	100\nchar:	'd'\nfloat:	100.0f\ndouble:	100.0\n");
	check(12, "hh", "type conversion not possible\n");
	check(13, "-", "int:	45\nchar:	'-'\nfloat:	45.0f\ndouble:	45.0\n");
	check(14, "+", "int:	43\nchar:	'+'\nfloat:	43.0f\ndouble:	43.0\n");
	check(15, "\n", "int:	10\nchar:	not displayable\nfloat:	10.0f\ndouble:	10.0\n");
	std::cout << std::endl;
}

void	int_tests()
{
	std::cout << "//INT-TESTS//" << std::endl;
	check(1, "-2147483648", "int:	-2147483648\nchar:	not possible\nfloat:	-2.14748e+09.0f\ndouble:	-2.14748e+09.0\n");
	check(2, "2147483647", "int:	2147483647\nchar:	not possible\nfloat:	2.14748e+09.0f\ndouble:	2.14748e+09.0\n");
	check(3, "-2147483649", "overflow\n");
	check(4, "2147483648", "overflow\n");
	check(5, "46513736738163879791586443487961797897179654841656431316456464613546466466679764644646986", "overflow\n");
	check(6, "-46513736738163879791586443487961797897179654841656431316456464613546466466679764644646986", "overflow\n");
	std::cout << std::endl;
}

void	float_tests()
{
	std::cout << "//FLOAT-TESTS//" << std::endl;
	check(1, "-.2f", "type conversion not possible\n");
	check(2, "+.2f", "type conversion not possible\n");
	check(3, ".2f", "type conversion not possible\n");
	check(4, "-4.f", "type conversion not possible\n");
	check(5, "+4.f", "type conversion not possible\n");
	check(6, "4.f", "type conversion not possible\n");
	check(7, "4.2a", "type conversion not possible\n");
	check(8, "4.2f", "int:	4\nchar:	not displayable\nfloat:	4.2f\ndouble:	4.2\n");
	check(9, "nanf", "int:	not possible\nchar:	not possible\nfloat:	nanf\ndouble:	nan\n");
	check(10, "-inff", "int:	not possible\nchar:	not possible\nfloat:	-inff\ndouble:	-inf\n");
	check(11, "+inff", "int:	not possible\nchar:	not possible\nfloat:	inff\ndouble:	inf\n");
	check(12, "inff", "int:	not possible\nchar:	not possible\nfloat:	inff\ndouble:	inf\n");


	std::cout << std::endl;
}

void	double_tests()
{
	std::cout << "//DOUBLE-TESTS//" << std::endl;
	check(1, "-.2", "type conversion not possible\n");
	check(2, "+.2", "type conversion not possible\n");
	check(3, ".2", "type conversion not possible\n");
	check(4, "-4.", "type conversion not possible\n");
	check(5, "+4.", "type conversion not possible\n");
	check(6, "4.", "type conversion not possible\n");
	check(7, "4.2", "int:	4\nchar:	not displayable\nfloat:	4.2f\ndouble:	4.2\n");
	check(8, "nan", "int:	not possible\nchar:	not possible\nfloat:	nanf\ndouble:	nan\n");
	check(9, "-inf", "int:	not possible\nchar:	not possible\nfloat:	-inff\ndouble:	-inf\n");
	check(10, "+inf", "int:	not possible\nchar:	not possible\nfloat:	inff\ndouble:	inf\n");
	check(11, "inff", "int:	not possible\nchar:	not possible\nfloat:	inff\ndouble:	inf\n");
	std::cout << std::endl;
}

int	main()
{
	char_tests();
	int_tests();
	float_tests();
	double_tests();
}