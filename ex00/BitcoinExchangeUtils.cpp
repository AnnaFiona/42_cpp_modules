#include "BitcoinExchange.hpp"

int	stoi(const std::string str)
{
	std::stringstream	stream(str);
	int					i;

	stream >> i;
	return (i);
}

float	stof(const std::string str)
{
	std::stringstream	stream(str);
	float				f;

	stream >> f;
	return (f);
}

std::string	itos(const int i)
{
	std::stringstream	stream;
	std::string			str;

	stream << i;
	stream >> str;
	return (str);
}

std::string	ftos(const float f)
{
	std::stringstream	stream;
	std::string			str;

	stream << f;
	stream >> str;
	return (str);
}

bool	is_int(const std::string str)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
		if (!std::isdigit(*it))
			return (false);
	}
	return (true);
}