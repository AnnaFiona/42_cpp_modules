# include "tests.hpp"

void	in_and_decrement_tests()
{
	Fixed a(10);
	Fixed c(10);

	std::cout << "/// in- and decrement operators ///" << std::endl;
	compare("X++: ", a++, c, 'n');
	c.setRawBits(2561);
	compare(NULL, a, c, 'y');
	c.setRawBits(2562);
	compare("++X: ", ++a, c, 'n');
	compare(NULL, a, c, 'y');
	compare("X--: ", a--, c, 'n');
	c.setRawBits(2561);
	compare(NULL, a, c, 'y');
	c.setRawBits(2560);
	compare("--X: ", --a, c, 'n');
	compare(NULL, a, c, 'y');
	std::cout << std::endl;
}