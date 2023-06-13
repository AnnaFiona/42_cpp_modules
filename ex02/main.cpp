#include "Fixed.hpp"

int main( void )
{
	Fixed		a;
	Fixed	b( 10 );
	Fixed const	c( 42.42f );
	Fixed const	d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	if (b > c)
		std::cout << "worksssssssssssssssssssssssssssssssssss" << std::endl;
	std::cout << c + b << std::endl;
	std::cout << c - b << std::endl;
	std::cout << c * b << std::endl;
	std::cout << c / b << std::endl;


	std::cout << "a is " << b.toFloat() << std::endl;
	std::cout << "a is " << b << std::endl;
	std::cout << "a is " << b << std::endl;

////////////////////////////////////////////////////////////////////////7

	Fixed z(10);
	Fixed const y( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "plus:" << std::endl;
	std::cout << z << std::endl;
	std::cout << ++z << std::endl;
	std::cout << z << std::endl;
	std::cout << z++ << std::endl;
	std::cout << z << std::endl << std::endl;

	std::cout << "minus:" << std::endl;
	std::cout << z-- << std::endl;
	std::cout << z << std::endl;
	std::cout << --z << std::endl;

	Fixed	max(8388607.7499f);

	std::cout << "toInt: " << max.toInt() << std::endl;
	std::cout << "toFloat: " << max.toFloat() << std::endl;
	std::cout << "max: : " << max << std::endl;
	std::cout << y << std::endl;

	std::cout << Fixed::max( z, y ) << std::endl;

	return (0);
}