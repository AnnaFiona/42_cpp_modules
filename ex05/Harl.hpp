#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
	private:
		void		(Harl:: *functions[5])();
		std::string	complaints[4];

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		void does_nothing( void );

	public:
		Harl();
		~Harl();

		void complain( std::string level );
};

#endif