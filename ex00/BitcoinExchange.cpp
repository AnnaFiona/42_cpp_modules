#include "BitcoinExchange.hpp"

bool	is_valid_date(const int year, const int month, const int day)
{
	std::time_t	now = std::time(0);
	std::tm	*current_time = std::gmtime(&now);
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
        return false;

	if (year < 1900 || time.tm_year != year - 1900 || time.tm_mon != month - 1 || time.tm_mday != day)
		return false;

	//checks if the date is in the future
	if (year - 1900 > current_time->tm_year || \
		(year - 1900 == current_time->tm_year && time.tm_mon > current_time->tm_mon) || \
		(year - 1900 == current_time->tm_year && time.tm_mon >= current_time->tm_mon && time.tm_mday > current_time->tm_mday)) {
			return false;
		}
	return true;
}

void	check_time(std::string time)
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

	if (is_valid_date(stoi(year), stoi(month), stoi(day)) == false)
		throw std::runtime_error("Not a valid date");
}

void	process_line(std::map<std::string, int> &data, std::string line)
{
	std::stringstream	stream(line);
	std::string			time;
	std::string			pipe;
	int					value; //change to string
	std::string			end;

	stream >> time;
	check_time(time);
	stream >> pipe;
	if (pipe != "|")
		throw std::runtime_error("Syntax error in data base: Pipe");
	stream >> value;
	//check value
	stream >> end;

	if (!end.empty())
		throw std::runtime_error("Syntax error in data base---------");

	data[time]=value;
}

void	get_data(std::map<std::string, int> &data, std::string data_base_name)
{
	std::ifstream	data_base;
	std::string		line;

	data_base.open(data_base_name.c_str());
	if (!data_base)
		throw std::runtime_error("Could not open file");
	while (std::getline(data_base, line))
	{
		process_line(data, line); //adds element to data, or throws error
	}
}

void	BitcoinExchange(const std::string data_base_name/* , const std::string input_file */)
{
	std::map<std::string, int>	data;

	try {
		get_data(data, data_base_name);
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return ;
	}
}


int main()
{
	BitcoinExchange("db.csv");
}