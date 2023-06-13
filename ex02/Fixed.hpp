#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					RawBits;
		static const int	PointPosition = 8;	
	public:
	//con- and destructors
		Fixed();
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed(const Fixed &F);
		Fixed	&operator = (const Fixed &F);
		~Fixed();

	//get- and setter
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
	
	//member-functions
		float	toFloat( void ) const;
		int		toInt( void ) const;
		float	operator << (const Fixed &F); 

		//comparison-operators
		bool	operator > (const Fixed &F) const;
		bool	operator < (const Fixed &F) const;
		bool	operator >= (const Fixed &F) const;
		bool	operator <= (const Fixed &F) const;
		bool	operator == (const Fixed &F) const;
		bool	operator != (const Fixed &F) const;

		//arithmetic-operators
		float	operator + (const Fixed &F) const;
		float	operator - (const Fixed &F) const;
		float	operator * (const Fixed &F) const;
		float	operator / (const Fixed &F) const;

		//in- and decrement-operators
		Fixed	&operator++ ();
		Fixed	operator++ (int);
		Fixed	&operator-- ();
		Fixed	operator-- (int);

		//min and max
/* 		static Fixed	&min(Fixed &a, Fixed &b) const;
		static const Fixed	&min(const Fixed &a, const Fixed &b) const;
		static Fixed	&max(Fixed &a, Fixed &b) const;
		static const Fixed	&max(const Fixed &a, const Fixed &b)const; */
};

std::ostream& operator << (std::ostream &out, const Fixed &F);

#endif