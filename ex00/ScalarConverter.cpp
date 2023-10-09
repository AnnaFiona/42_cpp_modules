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
	std::stringstream	stream;
	double				d;
	float				f;
	char				c;
	int					i;

	stream << str;
	stream >> i;
	stream << str;
	static_cast<char>(stream) >> c;
	stream << str;
	stream >> f;
	stream << str;
	stream >> d;

	std::cout << "int:		" << i << std::endl;
	std::cout << "char:		" << c << std::endl;
	std::cout << "float:	" << f << std::endl;
	std::cout << "double:	" << d << std::endl;

}