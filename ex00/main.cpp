#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: please give one infile as argument." << std::endl;
		return (0);
	}
	BitcoinExchange("data_bases/data.csv", argv[1]);
}