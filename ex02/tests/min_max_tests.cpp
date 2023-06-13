#include "tests.hpp"

void	min_max_tests()
{
	Fixed		a(10);
	Fixed		b(a);
	Fixed		c;
	const Fixed	d(34);
	const Fixed	e(45);

	b++;
	std::cout << "/// min and max ///" << std::endl;
	c = b.min(a, b);
	compare("min: ", c, a, 'y');
	c = Fixed::max(a, b);
	compare("max: ", c, b, 'y');
	std::cout << std::endl;

	c = b.min(e, d);
	compare("const min: ", c, d, 'y');
	c = Fixed::max(e, d);
	compare("const max: ", c, e, 'y');
	std::cout << std::endl;
}