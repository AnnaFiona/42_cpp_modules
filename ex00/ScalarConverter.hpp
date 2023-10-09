#pragma once

#include <iostream>
#include <sstream>
#include <string>


class ScalarConverter
{
public:
//con- and destructors
	ScalarConverter();
	ScalarConverter(const ScalarConverter& S);
	ScalarConverter& operator = (const ScalarConverter& S);
	~ScalarConverter();

//methods
	static void	convert(const std::string str);
};