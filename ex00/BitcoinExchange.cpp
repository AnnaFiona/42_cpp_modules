#include "BitcoinExchange.hpp"

void	process_line(std::map<std::string, float> &data, const std::string line)
{
	std::stringstream	stream(line);
	std::string			time;
	std::string			pipe;
	std::string			value;
	std::string			end;

	stream >> time;
	stream >> pipe;
	stream >> value;
	stream >> end;

	check_time(time);
	check_value(value);
	if (pipe != "|" || !end.empty())
		throw std::runtime_error("Syntax error in line");

	std::cout << time << " | " << stof(value) << std::endl;
	data[time]=stof(value);
}

void	get_data(std::map<std::string, float> &data, const std::string data_base_name)
{
	std::ifstream	data_base;
	std::string		line;

	data_base.open(data_base_name.c_str());
	if (!data_base)
		throw std::runtime_error("Could not open file");
	while (std::getline(data_base, line))
	{
		process_line(data, line); //adds element to map or throws error
	}
}

void	BitcoinExchange(const std::string data_base_name/* , const std::string input_file */)
{
	std::map<std::string, float>	data;

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