#include "Harl.hpp"

//private member-functions
void Harl::debug( void )
{
	std::cout << "debug" << std::endl;
}
void Harl::info( void )
{
	std::cout << "info" << std::endl;
}
void Harl::warning( void )
{
	std::cout << "warning" << std::endl;
}
void Harl::error( void )
{
	std::cout << "error" << std::endl;
}
void Harl::does_nothing( void ) {}



//constructor
Harl::Harl()
{
	this->functions[0] = &Harl::debug;
	this->functions[1] = &Harl::info;
	this->functions[2] = &Harl::warning;
	this->functions[3] = &Harl::error;
	this->functions[4] = &Harl::does_nothing;

	this->complaints[0] = "debug";
	this->complaints[1] = "info";
	this->complaints[2] = "warning";
	this->complaints[3] = "error";
}
//destructor
Harl::~Harl() {}

//public member-function
void Harl::complain( std::string level )
{
	int	x = 0;

	while (x < 4 && this->complaints[x] != level)
		x++;
	(this->*functions[x])();
}