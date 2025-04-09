#include "PhoneBook.hpp"

int		main()
{
	std::string	input;
	PhoneBook	book;

	input = "";
	std::cout << "Please enter a command: ";
	while (std::getline(std::cin, input))
	{
		if (input == "ADD")
			book.add(&book);
		if (input == "SEARCH")
			book.search(&book);
		if (input == "EXIT")
			break;
		std::cout << "Please enter a command: ";
	}
}