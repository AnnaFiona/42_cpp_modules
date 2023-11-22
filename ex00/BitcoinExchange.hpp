#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <map>


//BitcoinExchange.cpp
void	process_line(std::map<std::string, float> &data, const std::string line);
void	get_data(std::map<std::string, float> &data, const std::string data_base_name);
void	BitcoinExchange(const std::string data_base_name/* , const std::string input_file */);

//BitcoinExchangeChecks.cpp
void	check_time(const std::string time);
void	check_value(const std::string value);

//BitcoinExchangeUtils.cpp
int			stoi(const std::string str);
float		stof(const std::string str);
std::string	itos(const int i);
std::string	ftos(const float f);
bool		is_int(const std::string str);
