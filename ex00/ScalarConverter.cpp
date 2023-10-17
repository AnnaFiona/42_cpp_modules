#include "ScalarConverter.hpp"

//con- and destructors
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& S)
{
	(*this) = S;
}
ScalarConverter& ScalarConverter::operator = (const ScalarConverter& S)
{
	(void)(S);
	return (*this);
}
ScalarConverter::~ScalarConverter() {}

//methods
void	ScalarConverter::convert(const std::string str)
{
	bool	fail = false;

	if (check_if_int(str) == true) {
		fail = print_int(str);
	}
	else if (check_if_char(str) == true) {
		fail = print_char(str);
	}
	else if (check_if_float(str) == true) {

	}
	else if (check_if_double(str) == true) {

	}
	else if (fail == false) 
		std::cout << "type conversion not possible" << std::endl;

	if (fail == true)
		std::cout << "overflow" << std::endl;
}