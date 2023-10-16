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
	std::istringstream stream(str);
	double	d;
	float	f;
	char	c;
	int		i;
	if (check_if_int(str) == true) {
		stream >> i;
		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
	}
	else if (check_if_char(str) == true) {
		stream >> c;
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else if (check_if_float(str) == true) {
		stream >> f;
		i = static_cast<int>(f);
		c = static_cast<char>(f);
		d = static_cast<double>(f);
	}
	else if (check_if_double(str) == true) {
		stream >> d;
		i = static_cast<int>(d);
		c = static_cast<char>(d);
		f = static_cast<float>(d);
	}
	else {
		std::cout << "type conversion not possible" << std::endl;
		return ;
	}

	std::cout << "int:	" << i << std::endl;
	std::cout << "char:	" << c << std::endl;
	std::cout << "float:	" << f << std::endl;
	std::cout << "double:	" << d << std::endl;
}