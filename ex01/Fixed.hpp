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
		float	operator << (const Fixed &F); 
		~Fixed();

	//get- and setter
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
	
	//member-functions
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream& operator << (std::ostream &out, const Fixed &F);

#endif