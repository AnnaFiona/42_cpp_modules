#include "tests.hpp"

void	arithmetric_tests(void)
{
	Fixed	a(23.79f);
	Fixed	b(23.7948f);
	Fixed	c(29);
	Fixed	d(-2);
	Fixed	e(0);
	c.setRawBits(2890);

	std::cout << "/// arithmetic operators ///" << std::endl;
	compare("+: ", e + d, -2.0, 'n');
	compare(NULL, d + a, 21.79, 'n');
	compare(NULL, c + b, 35.0838, 'n');
	compare(NULL, c + b, 35.082, 'y');

	compare("-: ", e - d, 2.0, 'n');
	compare(NULL, d - a, -25.79, 'n');
	compare(NULL, c - b, -12.5058, 'n');
	compare(NULL, c - b, -12.5039, 'y');

	compare("*: ", e * d, 0.0, 'n');
	compare(NULL, d * a, -47.58, 'n');
	compare(NULL, c * b, 268.6194972, 'n');
	compare(NULL, c * b, 268.6194972, 'y');

	compare("/: ", e / d, 0.0, 'n');
	compare(NULL, d / a, -0.084068937, 'n');
	compare(NULL, c / b, 0.474431388, 'y');
	std::cout << std::endl;
}