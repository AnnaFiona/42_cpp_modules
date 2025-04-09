#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

//con- and destructors
Intern::Intern() {}
Intern::Intern(const Intern& I)
{
	(*this) = I;
}
Intern& Intern::operator = (const Intern& I)
{
	(void)I;
	return (*this);
}
Intern::~Intern() {}

//member-function
AForm*	Intern::makeForm(const std::string form_name, const std::string target) const
{
	std::string	forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm		*new_form;
	int			x = 0;

	while (x < 3)
	{
		if (form_name == forms[x])
			break;
		x++;
	}
	switch (x)
	{
		case 0 :
			try {
				new_form = new PresidentialPardonForm(target);
			} catch (std::bad_alloc& ba) {
				std::cout << ba.what();
			}
			break;
		case 1 :
			try {
				new_form = new RobotomyRequestForm(target);
			} catch (std::bad_alloc& ba) {
				std::cout << ba.what();
			}
			break;
		case 2 :
			try {
				new_form = new ShrubberyCreationForm(target);
			} catch (std::bad_alloc& ba) {
				std::cout << ba.what();
			}
			break;
		default :
			std::cout << "There is no form called " << form_name << std::endl;
			return (NULL);
	}
	std::cout << "Intern creates " << forms[x] << " form " << std::endl;
	return (new_form);
}