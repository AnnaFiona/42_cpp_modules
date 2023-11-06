#pragma once

#include <stdexcept>
#include <iostream>
#include <string>

template<typename T>
int	easyfind(const T container, const int num) throw(std::invalid_argument) {

	for (typename T::const_iterator	i = container.begin(); i != container.end(); i++) {
		if (*i == num)
			return (*i);
	}
	throw (std::invalid_argument("num is not in the container"));
}

template<typename T>
void	check(const int test_nr, const T container, const int num)
{
	std::string	red_bold("\033[1;31m");
	std::string	yellow("\033[0;33m");
	std::string white("\033[0m");
	std::string green("\033[0;32m");


	int			output;

	try {
		output = easyfind<T>(container, num);
	} catch (std::exception &e) {
		std::cout << test_nr << ": " << e.what() << std::endl;
		return ;
	}

	if (output == num)
		std::cout << green << test_nr << ": OK" << white << std::endl;
	else
	{
		std::cout << red_bold << test_nr << ": FAIL: " << white << std::endl;
		std::cout << yellow << "expected output:" << white << std::endl << num;
		std::cout << yellow << "function output:" << white << std::endl << output << std::endl;
	}
}