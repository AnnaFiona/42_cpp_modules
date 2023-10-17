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

	stream >> c;
	if (stream.fail())
		return true;

	std::cout << "int:	" << static_cast<int>(c) << std::endl;
	std::cout << "char:	" << c << std::endl;
	std::cout << "float:	" << static_cast<float>(c) << std::endl;
	std::cout << "double:	" << static_cast<double>(c) << std::endl;
	return false;
}