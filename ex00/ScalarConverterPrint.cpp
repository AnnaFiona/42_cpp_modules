#include "ScalarConverter.hpp"

bool	print_int(const std::string str)
{
	std::istringstream stream(str);
	int		i;

	stream >> i;
	if (stream.fail())
		return true;
	std::cout << "int:	" << i << std::endl;

	if (i >= 0 && i <= 127)
	{
		if (i >= 32 && i <= 126)
			std::cout << "char:	'" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "char:	not displayable" << std::endl;
	}
	else
		std::cout << "char:	not possible" << std::endl;
	std::cout << "float:	" << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double:	" << static_cast<double>(i) << ".0" << std::endl;
	return false;
}

bool	print_char(const std::string str)
{
	std::istringstream stream(str);
	char	c;

	stream >> c;
	if (stream.fail() && str != " ")
	{
		c = str.at(0);
		std::cout << "int:	" << static_cast<int>(c) << std::endl;
		std::cout << "char:	not displayable" << std::endl;
	}
	else
	{
		if (str == " ")
			c = str.at(0);
		std::cout << "int:	" << static_cast<int>(c) << std::endl;
		std::cout << "char:	'" << c << "'" << std::endl;
	}

	std::cout << "float:	" << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double:	" << static_cast<double>(c) << ".0" << std::endl;
	return false;
}

bool	print_float(const std::string str)
{
	std::istringstream	stream(str);
	float	f_check;
	float	f;

	if (str == "nanf" || str == "-inff" || str == "+inff" || str == "inff")
	{
		print_nan_inf(str, 'f');
		return false;
	}
	stream >> f;
	if (stream.fail())
		return true;

	print_int_and_char(str, f);
	f_check = static_cast<int>(f);
	if (f == f_check)
	{
		std::cout << "float:	" << f << ".0f" << std::endl;
		std::cout << "double:	" << static_cast<double>(f) << ".0" << std::endl;
	}
	else
	{
		std::cout << "float:	" << f << "f" << std::endl;
		std::cout << "double:	" << static_cast<double>(f) << std::endl;
	}
	return false;
}

bool	print_double(const std::string str)
{
	std::istringstream	stream_float(str);
	std::istringstream	stream(str);
	double	d;
	float	f_check;
	float	f;

	if (str == "nan" || str == "-inf" || str == "+inf" || str == "inf")
	{
		print_nan_inf(str, 'd');
		return false;
	}
	stream >> d;
	if (stream.fail())
		return true;
	
	print_int_and_char(str, d);
	stream_float >> f;
	if (stream_float.fail())
		std::cout << "float:	not possible" << std::endl;
	else
	{
		f_check = static_cast<int>(f);
		if (f == f_check)
			std::cout << "float:	" << static_cast<float>(d) << ".0f" << std::endl;
		else
			std::cout << "float:	" << static_cast<float>(d) << "f" << std::endl;
	}
	f_check = static_cast<int>(f);
	if (f == f_check)
		std::cout << "double:	" << d << ".0" << std::endl;
	else
		std::cout << "double:	" << d << std::endl;
	return false;
}
