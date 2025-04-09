#include "ScalarConverter.hpp"

void	print_nan_inf(const std::string str, const char float_or_double)
{
	double	d;
	float	f;

	std::cout << "int:	not possible" << std::endl;
	std::cout << "char:	not possible" << std::endl;
	if (float_or_double == 'f')
	{
		f = atof(str.c_str());
		std::cout << "float:	" << f << "f" << std::endl;
		std::cout << "double:	" << static_cast<double>(f) << std::endl;
	}
	else
	{
		d = atof(str.c_str());
		std::cout << "float:	" << static_cast<double>(d) << "f" << std::endl;
		std::cout << "double:	" << d << std::endl;
	}
}

void	print_int_and_char(const std::string str, const float f)
{	
	std::istringstream	stream_int(str);
	int		i;

	stream_int >> i;
	if (stream_int.fail())
		std::cout << "int:	not possible" << std::endl;
	else
		std::cout << "int:	" << static_cast<int>(f) << std::endl;

	if (stream_int.fail() || i < 0 || i > 127)
		std::cout << "char:	not possible" << std::endl;
	else if (i >= 32 && i <= 126)
		std::cout << "char:	'" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "char:	not displayable" << std::endl;
}

void	print_int_and_char(const std::string str, const double d)
{	
	std::istringstream	stream_int(str);
	int		i;

	stream_int >> i;
	if (stream_int.fail())
		std::cout << "int:	not possible" << std::endl;
	else
		std::cout << "int:	" << static_cast<int>(d) << std::endl;

	if (stream_int.fail() || i < 0 || i > 127)
		std::cout << "char:	not possible" << std::endl;
	else if (i >= 32 && i <= 126)
		std::cout << "char:	'" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char:	not displayable" << std::endl;
}
