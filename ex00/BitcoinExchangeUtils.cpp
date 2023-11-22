#include "BitcoinExchange.hpp"

int	stoi(const std::string str)
{
	std::stringstream	stream(str);
	int					i;

	stream >> i;
	return (i);
}