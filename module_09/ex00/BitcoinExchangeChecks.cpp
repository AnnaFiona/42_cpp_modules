#include "BitcoinExchange.hpp"

static std::tm	init_time(const int year, const int month, const int day)
{
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
	return (time);
}

static bool	is_valid_date(const int year, const int month, const int day)
{
	std::time_t	now_t = std::time(0);
	std::tm	*now = std::gmtime(&now_t);
	std::tm	time = init_time(year, month, day);

	if (std::mktime(&time) == -1)
        return (false);
	//checks if date is valid
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

bool	is_valid_time(const std::string time)
{
	std::stringstream	stream(time);
	std::string			year;
	std::string			month;
	std::string			day;

	std::getline(stream, year, '-');
	std::getline(stream, month, '-');
	std::getline(stream, day);

	if (year.size() != 4 || month.size() != 2 || day.size() != 2)
		return (false);
	if (!is_int(year) || !is_int(month) || !is_int(day))
		return (false);
	if (is_valid_date(stoi_(year), stoi_(month), stoi_(day)) == false)
		return (false);
	return (true);
}

void	check_value(const std::string line, const std::string value, const float max_value)
{
	if (!is_float(value) && !is_int(value))
		throw std::runtime_error("bad input => " + line);
	if (stof_(value) < 0.0)
		throw std::runtime_error("not a positive number.");
	if (stof_(value) > max_value)
		throw std::runtime_error("too large a number.");
}