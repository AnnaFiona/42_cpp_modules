#include "BitcoinExchange.hpp"

std::pair<std::string, float>	process_data_line(const std::string line)
{
	std::pair<std::string, float>	pair;
	std::stringstream	stream(line);
	std::string			time;
	std::string			value;

	std::getline(stream, time, ',');
	std::getline(stream, value);

	if (!is_valid_time(time)) //returns bool
		throw std::runtime_error("bad input => " + line);
	check_value(line, value, 2147483647.0); //throws error

	pair.first = time;
	pair.second = stof_(value);
	return (pair);
}

void	get_data(std::map<std::string, float>& data, const std::string data_base_name)
{
	std::ifstream	data_base;
	std::string		line;

	data_base.open(data_base_name.c_str());
	if (!data_base)
		throw std::runtime_error("could not open 'data.csv'");

	std::getline(data_base, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("bad input => " + line);

	while (std::getline(data_base, line))
	{
		try {
			data.insert(process_data_line(line)); //process_line returns pair or throws error
		} catch (std::exception& e) {
			std::cout << "Error: " << e.what() << " Will not use this line." << std::endl;
		}
	}
	data_base.close();
}



static float	get_rate(const std::map<std::string, float>& data, const std::pair<std::string, float>& pair)
{
	std::map<std::string, float>::const_iterator	it;

	it = data.upper_bound(pair.first);
	if (it != data.begin())
		it--;
	return (it->second * pair.second);
}

std::pair<std::string, float>	process_infile_line(const std::string line)
{
	std::pair<std::string, float>	pair;
	std::stringstream	stream(line);
	std::string			time;
	std::string			pipe;
	std::string			value;
	std::string			end;

	stream >> time;
	stream >> pipe;
	stream >> value;
	stream >> end;

	if (!is_valid_time(time)) //returns bool
		throw std::runtime_error("bad input => " + line);
	check_value(line, value, 1000.0); //throws error
	if (pipe != "|" || !end.empty())
		throw std::runtime_error("bad input => " + line);

	pair.first = time;
	pair.second = stof_(value);
	return (pair);
}

void	print_exchange(const std::map<std::string, float>& data, const std::string infile_name)
{
	std::pair<std::string, float>	pair;
	std::ifstream	infile;
	std::string		line;
	float			rate;

	infile.open(infile_name.c_str());
	if (!infile)
		throw std::runtime_error("could not open file");

	std::getline(infile, line);
	if (line != "date | value")
		throw std::runtime_error("bad input => " + line);

	while (std::getline(infile, line))
	{
		try {
			pair = process_infile_line(line);
			rate = get_rate(data, pair);
			std::cout << pair.first << " => " << pair.second << " = " << rate << std::endl;
		} catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	infile.close();
}

void	BitcoinExchange(const std::string data_base_name, const std::string infile_name)
{
	std::map<std::string, float>	data;

	try {
		get_data(data, data_base_name);
		print_exchange(data, infile_name);
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return ;
	}
}
