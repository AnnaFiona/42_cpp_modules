#include "BitcoinExchange.hpp"

static bool	is_valid_date(const int year, const int month, const int day)
{
	std::time_t	now_t = std::time(0);
	std::tm	*now = std::gmtime(&now_t);
	std::tm	time;

	time.tm_gmtoff = 0;
	time.tm_hour = 0;
	time.tm_isdst = 0;
	time.tm_mday = day;
	time.tm_min = 0;
	time.tm_mon = month - 1;
	time.tm_sec = 0;
	time.tm_wday = 0;
	time.tm_yday = 0;
	time.tm_year = year - 1900;
	time.tm_zone = 0;

	if (std::mktime(&time) == -1)
        return (false);

	if (year < 1900 || time.tm_year != year - 1900 || time.tm_mon != month - 1 || time.tm_mday != day)
		return (false);

	//checks if the date is in the future
	if (year - 1900 > now->tm_year || \
		(year - 1900 == now->tm_year && time.tm_mon > now->tm_mon) || \
		(year - 1900 == now->tm_year && time.tm_mon >= now->tm_mon && time.tm_mday > now->tm_mday)) {
			return (false);
	}
	return (true);
}

void	check_time(const std::string time)
{
	std::stringstream	stream(time);
	std::string			year;
	std::string			month;
	std::string			day;

	std::getline(stream, year, '-');
	std::getline(stream, month, '-');
	std::getline(stream, day);

	if (year.size() != 4 || month.size() != 2 || day.size() != 2)
		throw std::runtime_error("Syntax error in data base: Time");
	if (!is_int(year) || !is_int(month) || !is_int(day))
		throw std::runtime_error("Syntax error in data base: Time not numbers");
	if (is_valid_date(stoi(year), stoi(month), stoi(day)) == false)
		throw std::runtime_error("Not a valid date");
}

void	check_value(const std::string value)
{
	//std::string			control_str;
	float				f;

	f = stof(value);
/* 	control_str = ftos(f);

	if (value != control_str)
		throw std::runtime_error("Wrong value"); */
	if (f < 0.0 || f > 1000.0)
		throw std::runtime_error("Value out of range");
}