#include "PhoneBook.hpp"

//default-constructer
Contact::Contact()
{
	_FirstName = "";
	_LastName = "";
	_Nickname = "";
	_PhoneNumber = "";
	_DarkestSecret = "";
}

//getter
std::string	Contact::get_FirstName()
{
	return(this->_FirstName);
}
std::string	Contact::get_LastName()
{
	return(this->_LastName);
}
std::string	Contact::get_Nickname()
{
	return(this->_Nickname);
}
std::string	Contact::get_PhoneNumber()
{
	return(this->_PhoneNumber);
}
std::string	Contact::get_DarkestSecret()
{
	return(this->_DarkestSecret);
}

//setter
void	Contact::set_FirstName(std::string info)
{
	this->_FirstName = info;
}
void	Contact::set_LastName(std::string info)
{
	this->_LastName = info;
}
void	Contact::set_Nickname(std::string info)
{
	this->_Nickname = info;
}
void	Contact::set_PhoneNumber(std::string info)
{
	this->_PhoneNumber = info;
}
void	Contact::set_DarkestSecret(std::string info)
{
	this->_DarkestSecret = info;
}