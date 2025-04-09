#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
	Bureaucrat	b("Norbert", 2);
	Intern		intern;
	AForm		*wrong_form = intern.makeForm("wrong form", "wrong");
	AForm		*empty = intern.makeForm("", "empty");
	AForm		*ppf = intern.makeForm("presidential pardon", "Marta");
	AForm		*rrf = intern.makeForm("robotomy request", "a kidnapped individual");
	AForm		*scf = intern.makeForm("shrubbery creation", "Santas_toy_factory");

	std::cout << "-----------------------------------------------------" << std::endl;
	(void)wrong_form;
	(void)empty;
	b.signForm(*ppf);
	b.signForm(*rrf);
	b.signForm(*scf);
	std::cout << "-----------------------------------------------------" << std::endl;
	ppf->execute(b);
	rrf->execute(b);
	scf->execute(b);

	delete scf;
	delete rrf;
	delete ppf;
	delete empty;
	delete wrong_form;
	std::cout << "-----------------------------------------------------" << std::endl;
}
