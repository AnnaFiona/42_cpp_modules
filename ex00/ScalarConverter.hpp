#pragma once

#include <iostream>
#include <cstdlib>
#include <string>


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
	static void	convert(const char *str);
};