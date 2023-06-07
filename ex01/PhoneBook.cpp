#include "PhoneBook.hpp"

//constructer
PhoneBook::PhoneBook()
{
	this->_OldestContact = 0;
}

//getter
int		PhoneBook::get_OldestContact()
{
	return(PhoneBook::_OldestContact);
}

//member-functions
void	PhoneBook::raise_OldestContact()
{
	this->_OldestContact++;
	this->_OldestContact = this->_OldestContact % 8;
}

int	PhoneBook::get_index_add(PhoneBook *book)
{
	int	x = book->get_OldestContact();
	if (book->contacts[x].get_FirstName() != "")
	{
		book->contacts[x].set_FirstName("");
		book->contacts[x].set_LastName("");
		book->contacts[x].set_Nickname("");
		book->contacts[x].set_PhoneNumber("");
		book->contacts[x].set_DarkestSecret("");
	}
	book->raise_OldestContact();
	return (x);
}
std::string	PhoneBook::get_info(std::string info, std::string message)
{
	std::cout << "Please enter " << message << ": ";
	while (std::getline(std::cin, info))
	{
		if (info != "")
			break;
		std::cout << "Please enter " << message << ": ";
	}
	return (info);
}
void	PhoneBook::add(PhoneBook *book)
{
	int	x;

	x = get_index_add(book);
	book->contacts[x].set_FirstName(get_info(book->contacts[x].get_FirstName(), "first name"));
	book->contacts[x].set_LastName(get_info(book->contacts[x].get_LastName(), "last name"));
	book->contacts[x].set_Nickname(get_info(book->contacts[x].get_Nickname(), "nickname"));
	book->contacts[x].set_PhoneNumber(get_info(book->contacts[x].get_PhoneNumber(), "phone number"));
	book->contacts[x].set_DarkestSecret(get_info(book->contacts[x].get_DarkestSecret(), "darkest secret"));
}