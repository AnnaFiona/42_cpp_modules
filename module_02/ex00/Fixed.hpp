#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					RawBits;
		static const int	PointPosition = 8;	
	public:
	//con- and destructors
		Fixed();
		Fixed(const Fixed &F);
		Fixed	&operator = (const Fixed &F);
		~Fixed();

	//get- and setter
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};


#endif