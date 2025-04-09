#include "tests.hpp"

void	comparison_tests()
{
	Fixed	a(23.79f);
	Fixed	b(23.7948f);
	Fixed	c(29);
	Fixed	d(-2);
	Fixed	e(0);
	c.setRawBits(2890);

	std::cout << "/// comparison operators ///" << std::endl;
	std::cout << ">: ";
	if (d > 0)
		fail();
	else {ok();}
	if (b > a)
		ok();
	else {fail();}
	std::cout << std::endl;

	std::cout << "<: ";
	if (d < 0)
		ok();
	else {fail();}
	if (b < a)
		fail();
	else {ok();}
	std::cout << std::endl;

	std::cout << ">=: ";
	if (e >= 0)
		ok();
	else {fail();}
	if (a >= b)
		fail();
	else {ok();}
	std::cout << std::endl;

	std::cout << "<=: ";
	if (d <= e)
		ok();
	else {fail();}
	if (b <= a)
		fail();
	else {ok();}
	std::cout << std::endl;

	std::cout << "==: ";
	if (e == 0)
		ok();
	else {fail();}
	if (a == b)
		fail();
	else {ok();}
	std::cout << std::endl;

	std::cout << "!=: ";
	if (b != a)
		ok();
	else {fail();}
	if (e != 0)
		fail();
	else {ok();}
	std::cout << std::endl;
	std::cout << std::endl;
}