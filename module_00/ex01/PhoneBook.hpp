#ifndef PHONEBOOK_H
# define  PHONEBOOK_H

# include <iostream>
# include <iomanip>

class Contact
{
	private:
	std::string	_FirstName;
	std::string	_LastName;
	std::string	_Nickname;
	std::string	_PhoneNumber;
	std::string	_DarkestSecret;

	public:
	Contact();

	//getter
	std::string	get_FirstName();
	std::string	get_LastName();
	std::string	get_Nickname();
	std::string	get_PhoneNumber();
	std::string	get_DarkestSecret();
	//setter
	void	set_FirstName(std::string info);
	void	set_LastName(std::string info);
	void	set_Nickname(std::string info);
	void	set_PhoneNumber(std::string info);
	void	set_DarkestSecret(std::string info);
};

class PhoneBook
{
	private:
	int			_OldestContact;
	Contact		contacts[8];

	//add
	std::string	get_info(std::string info, std::string message);
	int			get_index_add(PhoneBook *book);
	//search
	void	print_selected_contact(PhoneBook* book, int index);
	int		get_index_search(PhoneBook *book);
	int		convert_input(PhoneBook *book, std::string input);
	void	print_contacts(PhoneBook *book);
	void	print_max_ten(std::string str);

	public:
	PhoneBook();

	int		get_OldestContact();

	void	raise_OldestContact();
	void	add(PhoneBook *book);
	void	search(PhoneBook *book);
};

#endif