#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <map>

//is_???() functions return bool

//BitcoinExchange.cpp
std::pair<std::string, float>	process_line(const std::string line);
void	get_data(std::map<std::string, float>& data, const std::string data_base_name);
void	print_exchange(const std::map<std::string, float>& data, const std::string infile_name);
void	BitcoinExchange(const std::string data_base_name, const std::string input_file);

//BitcoinExchangeChecks.cpp
bool	is_valid_time(const std::string time);
void	check_value(const std::string line, const std::string value, const float max_value);

//BitcoinExchangeUtils.cpp
int			stoi_(const std::string str);
float		stof_(const std::string str);
std::string	itos_(const int i);
std::string	ftos_(const float f);
bool		is_int(const std::string str);
bool		is_float(const std::string str);