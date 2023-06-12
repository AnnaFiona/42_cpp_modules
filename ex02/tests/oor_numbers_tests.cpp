#include "tests.hpp"

void	oor_numbers_tests()
{
	Fixed	pmax(8388607);
	Fixed	nmax(-8388608);
	Fixed	pmaxo(8388608);
	Fixed	nmaxo(-8388609);

	std::cout << "/// out of range numbers ///" << std::endl;
	compare("rawBits pos max: ", pmax.getRawBits(), 2147483392, 'y');
	compare("rawBits neg max: ", nmax.getRawBits(), -2147483648, 'y');
	compare("positive max(8388607): ", pmax.toInt(), 8388607, 'y');
	compare("negative max(-8388608): ", nmax.toInt(), -8388608, 'y');
	std::cout << std::endl;
	compare("rawBits pos max+1: ", pmaxo.getRawBits(), 8388608, 'y');
	compare("rawBits neg max-1: ", nmaxo.getRawBits(), -8388609, 'y');
	compare("positive max+1(8388608): ", pmaxo.toInt(), 8388608, 'y');
	compare("negative max-1(-8388609): ", nmaxo.toInt(), -8388609, 'y');
}