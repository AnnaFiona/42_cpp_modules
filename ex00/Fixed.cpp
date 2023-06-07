#include "Fixed.hpp"

//con- and destructors
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->RawBits = 0;
}
Fixed::Fixed(const Fixed &F)
{
	std::cout << "Copy constructor called" << std::endl;
	this->RawBits = F.getRawBits();
}
Fixed	&Fixed::operator = (const Fixed &F)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->RawBits = F.getRawBits();
	return (*this);
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//get- and setter
int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->RawBits);
}
void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits memebr function called" << std::endl;
	this->RawBits = raw;
}