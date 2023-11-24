#include "BitcoinExchange.hpp"

int	stoi_(const std::string str)
{
	std::stringstream	stream(str);
	int					i;

	stream >> i;
	return (i);
}

float	stof_(const std::string str)
{
	std::stringstream	stream(str);
	float				f;

	stream >> f;
	return (f);
}

std::string	itos_(const int i)
{
	std::stringstream	stream;
	std::string			str;

	stream << i;
	stream >> str;
	return (str);
}

std::string	ftos_(const float f)
{
	std::stringstream	stream;
	std::string			str;

	stream << f;
	stream >> str;
	return (str);
}

bool	is_int(const std::string str)
{
	std::string::const_iterator it = str.begin();

	if (*it == '-')
		it++;
	while (it != str.end())
	{
		if (!std::isdigit(*it))
			return (false);
		it++;
	}
	return (true);
}

bool	is_float(const std::string str)
{
	std::string::const_iterator it = str.begin();
	bool	digit = false;

	if (*it == '-')
		it++;
	while (*it != '.')
	{
		digit = true;
		if (!std::isdigit(*it) || it == str.end())
			return (false);
		it++;
	}
	if (!digit)
		return (false);
	digit = false;
	it++;
	while (it != str.end())
	{
		digit = true;
		if (!std::isdigit(*it))
			return (false);
		it++;
	}
	if (!digit)
		return (false);
	return (true);
}