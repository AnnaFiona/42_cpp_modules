#include "tests.hpp"

void	oor_numbers_tests()
{
	Fixed	pmax(8388607.74f);
	Fixed	nmax(-8388608);
	Fixed	pmaxo(8388607.75f);
	Fixed	nmaxo(-8388609);

	std::cout << "/// out of range numbers ///" << std::endl;
	compare("rawBits pos max: ", pmax.getRawBits(), 2147483520, 'y');
	//rawBits pos max is 2147483520 and not 2147483647, because a higher input number than 8388607.74f would overflow (I think because it would round up)
	compare("rawBits neg max: ", nmax.getRawBits(), -2147483648, 'y');
	compare("positive max(8388607): ", pmax.toInt(), 8388607, 'y');
	compare("negative max(-8388608): ", nmax.toInt(), -8388608, 'y');
	std::cout << std::endl;
	compare("rawBits pos max+1(overflows): ", pmaxo.getRawBits(), -2147483648, 'y');
	compare("rawBits neg max-1(overflows): ", nmaxo.getRawBits(), 2147483392, 'y');
	compare("positive max+1(overflows): ", pmaxo.toInt(), -8388608, 'y');
	compare("negative max-1(overflows): ", nmaxo.toInt(), 8388607, 'y');
}