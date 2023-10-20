#include "ScalarConverter.hpp"

bool	print_int(const std::string str)
{
	std::istringstream stream(str);
	int		i;

	std::cout << "int" << std::endl;

	stream >> i;
	if (stream.fail())
		return true;
	std::cout << "int:	" << i << std::endl;

	if (i >= 0 && i <= 127)
	{
		if (i >= 32 && i <= 126)
			std::cout << "char:	" << static_cast<char>(i) << std::endl;
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

	std::cout << "char" << std::endl;

	stream >> c;
	if (stream.fail())
		return true;

	std::cout << "int:	" << static_cast<int>(c) << std::endl;
	std::cout << "char:	" << c << std::endl;
	std::cout << "float:	" << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double:	" << static_cast<double>(c) << ".0" << std::endl;
	return false;
}


static void	print_int_and_char(const std::string str, const float f)
{	
	std::istringstream	stream_int(str);
	int		i;

	stream_int >> i;
	if (stream_int.fail())
		std::cout << "int:	not possible" << std::endl;
	else
		std::cout << "int:	" << static_cast<int>(f) << std::endl;

	if (stream_int.fail() || i < 0 || i > 127)
		std::cout << "char:	not possible" << std::endl;
	else if (i >= 32 && i <= 126)
		std::cout << "char:	" << static_cast<char>(f) << std::endl;
	else
		std::cout << "char:	not displayable" << std::endl;
}

bool	print_float(const std::string str)
{
	std::istringstream	stream(str);
	float	f_check;
	float	f;

	std::cout << "float" << std::endl;

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

static void	print_int_and_char(const std::string str, const double d)
{	
	std::istringstream	stream_int(str);
	int		i;

	stream_int >> i;
	if (stream_int.fail())
		std::cout << "int:	not possible" << std::endl;
	else
		std::cout << "int:	" << static_cast<int>(d) << std::endl;

	if (stream_int.fail() || i < 0 || i > 127)
		std::cout << "char:	not possible" << std::endl;
	else if (i >= 32 && i <= 126)
		std::cout << "char:	" << static_cast<char>(d) << std::endl;
	else
		std::cout << "char:	not displayable" << std::endl;
}

bool	print_double(const std::string str)
{
	std::istringstream	stream_float(str);
	std::istringstream	stream(str);
	double	d;
	float	f_check;
	float	f;

	std::cout << "double" << std::endl;

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
