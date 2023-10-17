#pragma once

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <limits>


class ScalarConverter
{
private:
//con- and destructors
	ScalarConverter();
	ScalarConverter(const ScalarConverter& S);
	ScalarConverter& operator = (const ScalarConverter& S);
	~ScalarConverter();

public:
//methods
	static void	convert(const std::string str);
};


//ScalarConverterGetTypes.cpp
bool	check_if_int(const std::string str);
bool	check_if_char(const std::string str);
bool	check_if_float(const std::string str);
bool	check_if_double(const std::string str);

//ScalarConverterPrintUtils.cpp
bool	print_int(const std::string str);
bool	print_char(const std::string str);
