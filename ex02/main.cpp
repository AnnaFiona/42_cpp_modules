#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
	PresidentialPardonForm	p;
	ShrubberyCreationForm	s;
	RobotomyRequestForm		r;
	Bureaucrat				b("b", 5);

	r.beSigned(b);
	r.execute(b);
	r.execute(b);
	r.execute(b);
	r.execute(b);
	r.execute(b);
	r.execute(b);
	r.execute(b);
	r.execute(b);
}
