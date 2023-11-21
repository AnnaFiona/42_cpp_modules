#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

void	process_line(std::map<std::string, int> &data, std::string line)
{
	std::stringstream	stream(line);
	std::string			time;
	std::string			pipe;
	int					value; //change to string
	std::string			end;

	stream >> time;
	//check time
	stream >> pipe;
	if (pipe != "|")
		throw std::runtime_error("Syntax error in data base");
	stream >> value;
	//check value
	stream >> end;

	if (!end.empty())
		throw std::runtime_error("Syntax error in data base---------");

	data[time]=value;
	std::cout << time << " | " << value << std::endl;
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
		process_line(data, line);
		data["f"]=4;
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