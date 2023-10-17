#include "ScalarConverter.hpp"

bool	check_if_int(const std::string str)
{
	size_t	x = 0;

	if (str[0] == '-' || str[0] == '+')
		x++;
	if (str.length() == x)
		return (false);
	while (str.length() > x)
	{
		if (str[x] < '0' || str[x] > '9')
			return (false);
		x++;
	}
	return (true);
}

bool	check_if_char(const std::string str)
{
	if (str[0] >= 32 && str[0] <= 126 && str.length() == 1)
		return (true);
	return (false);
}

bool	check_if_float(const std::string str)
{
	size_t	x = 0;
	bool	digit = false;

	if (str == "nanf" || str == "-inff" || str == "+inff" || str == "inff")
		return (true);
	if (str[0] == '-' || str[0] == '+')
		x++;
	while (str.length() > x && str[x] >= '0' && str[x] <= '9')
	{
		digit = true;
		x++;
	}
	if (str[x] != '.' || digit == false)
		return (false);
	x++;
	digit = false;
	while (str.length() > x && str[x] >= '0' && str[x] <= '9')
	{
		digit = true;
		x++;
	}
	if (str[x] != 'f' || digit == false)
		return (false);
	if (str.length() != x + 1)
		return (false);
	std::cout << "f: " << str[x] << std::endl;
	return (true);
}

bool	check_if_double(const std::string str)
{
	size_t	x = 0;
	bool	digit = false;

	if (str == "nan" || str == "-inf" || str == "+inf" || str == "inf")
		return (true);
	if (str.length() == x)
		return (false);
	while (str.length() > x && str[x] >= '0' && str[x] <= '9')
	{
		digit = true;
		x++;
	}
	if (str[x] != '.' || digit == false)
		return (false);
	x++;
	digit = false;
	while (str.length() > x && str[x] >= '0' && str[x] <= '9')
	{
		digit = true;
		x++;
	}
	if (digit == false || str.length() != x)
		return (false);
	std::cout << "d " << str[x] << std::endl;
	return (true);
}
