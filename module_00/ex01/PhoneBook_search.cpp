#include "PhoneBook.hpp"

void	PhoneBook::print_max_ten(std::string str)
{
	if (str.length() >= 10)
	{
		str = str.substr(0, 9);
		str = str + ".";
	}
	std::cout << std::setw(10) << str << "|";
}

void	PhoneBook::print_contacts(PhoneBook *book)
{
	for (int x = 0; book->contacts[x].get_FirstName() != "" && x < 8; x++)
	{
		std::cout << std::setw(10) << x + 1 << "|";
		print_max_ten(book->contacts[x].get_FirstName());
		print_max_ten(book->contacts[x].get_LastName());
		print_max_ten(book->contacts[x].get_Nickname());
		std::cout << std::endl;
	}
}

int		PhoneBook::convert_input(PhoneBook *book, std::string input)
{
	int	index = 0;
	int	x = 0;

	try {index = std::stoi(input);}
	catch(std::invalid_argument)
	{
		std::cout << "catch-error" << std::endl;
		return (-1);
	}
	while (book->contacts[x].get_FirstName() != "" && x < 8)
		x++;
	if (index < 1 || index > x)
		return (-1);
	return (index);
}

int		PhoneBook::get_index_search(PhoneBook *book)
{
	std::string	input = "";
	int index = 0;

	if (book->contacts[0].get_FirstName() == "")
	{
		std::cout << "-there are no saved contacts-" << std::endl;
		return (-1);
	}
	std::cout << "Please enter index: ";
	while (std::getline(std::cin, input))
	{
		if (input != "")
			break;
		std::cout << "Please enter index: ";
	}
	index = convert_input(book, input);
	if (index == -1)
		std::cout << "-invalid argument-" << std::endl;
	return (index - 1);
}

void	PhoneBook::print_selected_contact(PhoneBook *book, int index)
{
	std::cout \
	<< "first name:\t" << book->contacts[index].get_FirstName() << std::endl \
	<< "lastname:\t" << book->contacts[index].get_LastName() << std::endl \
	<< "nickname:\t" << book->contacts[index].get_Nickname() << std::endl \
	<< "phone number:\t" << book->contacts[index].get_PhoneNumber() << std::endl \
	<< "darkest secret:\t" << book->contacts[index].get_DarkestSecret() << std::endl;
}

void	PhoneBook::search(PhoneBook *book)
{
	int	index = 0;
	
	print_contacts(book);
	index = get_index_search(book);
	if (index < 0)
		return;
	print_selected_contact(book, index);
}