#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

void presidential_pardon_form_tests()
{
	Bureaucrat				b_execute("b_execute", 5);
	Bureaucrat				b_sign("b_sign", 26);
	PresidentialPardonForm	p;
	PresidentialPardonForm	ppf("ppf");
	PresidentialPardonForm	copy(p);

	b_sign.incrementGrade();
	ppf.beSigned(b_sign);
	b_sign.decrementGrade();
	std::cout << "1: " << "target of ppf: " << ppf.getTarget() << std::endl;
	std::cout << "2: " << "target of p: " << copy.getTarget() << std::endl;
	std::cout << "3: " << "target of copy: " << copy.getTarget() << std::endl;
	std::cout << "4: " << copy << std::endl;
	copy = ppf;
	std::cout << "5: " << "target of copy: " << copy.getTarget() << std::endl;
	std::cout << "6: " << copy << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;

	std::cout << "7: " << p << std::endl;
	b_execute.executeForm(p);
	b_sign.signForm(p);
	b_sign.incrementGrade();
	b_sign.signForm(p);
	b_execute.decrementGrade();
	b_execute.executeForm(p);
	b_execute.incrementGrade();
	b_execute.executeForm(p);
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
}

void robotomy_request_form_tests()
{
	Bureaucrat				b_execute("b_execute", 45);
	Bureaucrat				b_sign("b_sign", 73);
	RobotomyRequestForm	r;
	RobotomyRequestForm	rrf("rrf");
	RobotomyRequestForm	copy(r);

	b_sign.incrementGrade();
	rrf.beSigned(b_sign);
	b_sign.decrementGrade();
	std::cout << "8: " << "target of rrf: " << rrf.getTarget() << std::endl;
	std::cout << "9: " << "target of r: " << copy.getTarget() << std::endl;
	std::cout << "10: " << "target of copy: " << copy.getTarget() << std::endl;
	std::cout << "11: " << copy << std::endl;
	copy = rrf;
	std::cout << "12: " << "target of copy: " << copy.getTarget() << std::endl;
	std::cout << "13: " << copy << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;

	std::cout << r << std::endl;
	b_execute.executeForm(r);
	b_sign.signForm(r);
	b_sign.incrementGrade();
	b_sign.signForm(r);
	b_execute.decrementGrade();
	b_execute.executeForm(r);
	b_execute.incrementGrade();

	std::cout << std::endl;
	b_execute.executeForm(r);
	b_execute.executeForm(r);
	b_execute.executeForm(r);
	b_execute.executeForm(r);
	b_execute.executeForm(r);
	b_execute.executeForm(r);
	b_execute.executeForm(r);
	b_execute.executeForm(r);
	b_execute.executeForm(r);
	b_execute.executeForm(r);
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
}

void shrubbery_creation_form_tests()
{
	Bureaucrat				b_execute("b_execute", 137);
	Bureaucrat				b_sign("b_sign", 146);
	ShrubberyCreationForm	s;
	ShrubberyCreationForm	scf("scf");
	ShrubberyCreationForm	copy(s);

	b_sign.incrementGrade();
	scf.beSigned(b_sign);
	b_sign.decrementGrade();
	std::cout << "14: " << "target of scf: " << scf.getTarget() << std::endl;
	std::cout << "15: " << "target of s: " << copy.getTarget() << std::endl;
	std::cout << "16: " << "target of copy: " << copy.getTarget() << std::endl;
	std::cout << "17: " << copy << std::endl;
	copy = scf;
	std::cout << "18: " << "target of copy: " << copy.getTarget() << std::endl;
	std::cout << "19: " << copy << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;

	std::cout << s << std::endl;
	b_execute.executeForm(s);
	b_sign.signForm(s);
	b_sign.incrementGrade();
	b_sign.signForm(s);
	b_sign.signForm(scf);
	b_execute.decrementGrade();
	b_execute.executeForm(s);
	b_execute.incrementGrade();
	b_execute.executeForm(s);
	b_execute.executeForm(scf);
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
}

int main()
{
	presidential_pardon_form_tests();
	robotomy_request_form_tests();
	shrubbery_creation_form_tests();
}
