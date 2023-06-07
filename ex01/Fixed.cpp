#include "Fixed.hpp"

//con- and destructors
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->RawBits = 0;
}
Fixed::Fixed(const int raw)
{
	std::cout << "Int constructor called" << std::endl;
	this->RawBits = raw * 256;
}
Fixed::Fixed(const float raw)
{
	std::cout << "Float constructor called" << std::endl;
	this->RawBits = roundf(raw * 256);
}
Fixed::Fixed(const Fixed &F)
{
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(F);
}
Fixed	&Fixed::operator = (const Fixed &F)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->RawBits = F.getRawBits();
	return (*this);
}
float	Fixed::operator << (const Fixed &F)
{
	float	temp = F.toFloat();
	return (temp);
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
	std::cout << "setRawBits member function called" << std::endl;
	this->RawBits = raw;
}

//member-functions
float	Fixed::toFloat( void ) const
{
	float	temp = static_cast<float>(this->RawBits);

	temp /= 256;
	return (temp);
}
int		Fixed::toInt( void ) const
{
	return (this->RawBits/256);
}


//<<-operator overload function////////////////////////////////////////////////
std::ostream& operator << (std::ostream &out, const Fixed &F)
{
	return (out << F.toFloat());
}