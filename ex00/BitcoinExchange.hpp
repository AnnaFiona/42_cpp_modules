#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <map>


//BitcoinExchange.cpp
bool	is_valid_date(const int year, const int month, const int day);
void	check_time(std::string time);
void	process_line(std::map<std::string, int> &data, std::string line);
void	get_data(std::map<std::string, int> &data, std::string data_base_name);
void	BitcoinExchange(const std::string data_base_name/* , const std::string input_file */);

//BitcoinExchangeUtils.cpp
int	stoi(const std::string str);
