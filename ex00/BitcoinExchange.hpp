# pragma once

#include <map>


class BitcoinExchange
{
private:
	std::map<std::string, int>	_data;

public:
//con- and destructors	
BitcoinExchange();
BitcoinExchange(const std::string data_base_name);
~BitcoinExchange();
BitcoinExchange	BitcoinExchange(const BitcoinExchange &B);
BitcoinExchange	operator = (const BitcoinExchange &B);

};
