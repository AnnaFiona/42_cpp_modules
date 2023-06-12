#include "Fixed.hpp"

//con- and destructors
Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->RawBits = 0;
}
Fixed::Fixed(const int raw)
{
	//std::cout << "Int constructor called" << std::endl;
	if (raw > 8388608 || raw < -8388608)
		std::cerr << "warning: your number is out of range, it will overflow" << std::endl;
	else if (raw> 8388607)
		std::cerr << "warning: your number could be out of range, it might overflow" << std::endl;
	this->RawBits = raw * 256;
}
Fixed::Fixed(const float raw)
{
	//std::cout << "Float constructor called" << std::endl;
	if (raw > 8388608 || raw < -8388608)
		std::cerr << "warning: your number is out of range, it will overflow" << std::endl;
	else if (raw> 8388607)
		std::cerr << "warning: your number could be out of range, it might overflow" << std::endl;
	this->RawBits = roundf(raw * 256);
}
Fixed::Fixed(const Fixed &F)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->operator=(F);
}
Fixed	&Fixed::operator = (const Fixed &F)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->RawBits = F.getRawBits();
	return (*this);
}
Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

//get- and setter
int		Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->RawBits);
}
void	Fixed::setRawBits( int const raw )
{
	//std::cout << "setRawBits member function called" << std::endl;
	if (raw > 8388608 || raw < -8388608)
		std::cerr << "warning: your number is out of range, it will overflow" << std::endl;
	else if (raw> 8388607)
		std::cerr << "warning: your number could be out of range, it might overflow" << std::endl;
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
float	Fixed::operator << (const Fixed &F)
{
	float	temp = F.toFloat();
	return (temp);
}
//comparison-operators
bool	Fixed::operator > (const Fixed &F) const
{
	if (this->RawBits > F.RawBits)
		return (true);
	return (false);
}
bool	Fixed::operator < (const Fixed &F) const
{
	if (this->RawBits < F.RawBits)
		return (true);
	return (false);
}
bool	Fixed::operator >= (const Fixed &F) const
{
	if (this->RawBits >= F.RawBits)
		return (true);
	return (false);
}
bool	Fixed::operator <= (const Fixed &F) const
{
	if (this->RawBits <= F.RawBits)
		return (true);
	return (false);
}
bool	Fixed::operator == (const Fixed &F) const
{
	if (this->RawBits == F.RawBits)
		return (true);
	return (false);
}
bool	Fixed::operator != (const Fixed &F) const
{
	if (this->RawBits != F.RawBits)
		return (true);
	return (false);
}
//arithmetic-operators
float	Fixed::operator + (const Fixed &F) const
{
	float	temp = static_cast<float>(this->RawBits + F.RawBits);
	temp /= 256;
	return (temp);
}
float	Fixed::operator - (const Fixed &F) const
{
	float	temp = static_cast<float>(this->RawBits - F.RawBits);
	temp /= 256;
	return (temp);
}
float	Fixed::operator * (const Fixed &F) const
{
	float	temp = static_cast<float>(this->RawBits * F.RawBits);
	temp /= 65536;
	return (temp);
}
float	Fixed::operator / (const Fixed &F) const
{
	float	temp = static_cast<float>(this->RawBits / F.RawBits);
	//float	temp = this->toFloat() / F.toFloat();
	//temp *= 256;
	return (temp);
}

//in- and decrement-operators
Fixed	&Fixed::operator++ ()
{
	++this->RawBits;
	return (*this);
}
Fixed	Fixed::operator++ (int)
{
	Fixed	temp = *this;
	this->RawBits++;
	return (temp);
}
Fixed	&Fixed::operator-- ()
{
	--this->RawBits;
	return (*this);
}
Fixed	Fixed::operator-- (int)
{
	Fixed	temp = *this;
	this->RawBits--;
	return (temp);
}

//min and max (don't really know what to do when they are equal so I am just returning a, because throwing an error seems a bit excessive)
/* static Fixed	&min(Fixed &a, Fixed &b)
{
	if (b < a)
		return (b);
	return (a);
}
static const Fixed	&min(const Fixed &a, const Fixed &b)
{
	if (b < a)
		return (b);
	return (a);
}
static Fixed	&max(Fixed &a, Fixed &b)
{
	if (b > a)
		return (b);
	return (a);
}
static const Fixed	&max(const Fixed &a, const Fixed &b)
{
	if (b > a)
		return (b);
	return (a);
} */


//<<-operator overload function////////////////////////////////////////////////
std::ostream& operator << (std::ostream &out, const Fixed &F)
{
	return (out << F.toFloat());
}