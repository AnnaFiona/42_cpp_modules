#include "BitcoinExchange.hpp"


static bool	is_date_valid(year, month, day) //
	checks if date is valid
		return false
	checks if date is in future
		return false
	return true


bool	is_valid_time(string time) //
	splits line
	checks if int
		return (false);
	checks if valid date
		return (false);
	return (true);


void	check_value(string value) //
	if (!is_float(value) && !is_int(value)) //returns bool //utils
		throw: syntax error
	if (value out of range)
		throw: out of range value