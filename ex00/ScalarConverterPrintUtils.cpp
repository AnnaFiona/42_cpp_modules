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
	std::cout << "float:	" << static_cast<float>(i) << std::endl;
	std::cout << "double:	" << static_cast<double>(i) << std::endl;
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
	std::cout << "float:	" << static_cast<float>(c) << std::endl;
	std::cout << "double:	" << static_cast<double>(c) << std::endl;
	return false;
}

bool	print_float(const std::string str)
{
	std::istringstream stream(str);
	float	d;
	int		i;

	std::cout << "float" << std::endl;

	stream >> d;
	if (stream.fail())
		return true;
	
	stream >> i;
	if (stream.fail())
		std::cout << "int:	not possible" << std::endl;
	else
		std::cout << "int:	" << static_cast<int>(d) << std::endl;

	if (stream.fail() || i < 0 || i > 127)
		std::cout << "char:	not possible" << std::endl;
	else if (i >= 32 && i <= 126)
		std::cout << "char:	" << static_cast<char>(d) << std::endl;
	else
		std::cout << "char:	not displayable" << std::endl;

	std::cout << "float:	" << d << std::endl;
	std::cout << "double:	" << static_cast<double>(d) << std::endl;
	return false;
}

bool	print_double(const std::string str)
{
	std::istringstream stream_float(str);
	std::istringstream stream_int(str);
	std::istringstream stream(str);
	double	d;
	float	f;
	int		i;

	std::cout << "double" << std::endl;

	stream >> d;
	if (stream.fail())
		return true;
	
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

	stream_float >> f;
	if (stream_float.fail())
		std::cout << "float:	not possible" << std::endl;
	else
		std::cout << "float:	" << static_cast<float>(d) << std::endl;

	std::cout << "double:	" << d << std::endl;
	return false;
}
