#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

void presidential_pardon_form_tests()
{
	Bureaucrat				b_execute("b_execute", 6);
	Bureaucrat				b_sign("b_sign", 26);
	PresidentialPardonForm	p;
	PresidentialPardonForm	ppf("ppf");
	PresidentialPardonForm	copy(p);

	b_sign.incrementGrade();
	b_sign.signForm(ppf);
	b_sign.decrementGrade();
	std::cout << "1: " << "target of ppf: " << ppf.getTarget() << std::endl;
	std::cout << "2: " << "target of p: " << p.getTarget() << std::endl;
	std::cout << "3: " << "target of copy: " << copy.getTarget() << std::endl;
	std::cout << "4: " << copy << std::endl;
	copy = ppf;
	std::cout << "5: " << "target of copy: " << copy.getTarget() << std::endl;
	std::cout << "6: " << copy << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;

	std::cout << "7: " << p << std::endl;
	std::cout << "8: " << b_sign << std::endl;
	b_execute.executeForm(p);
	b_sign.signForm(p);
	b_sign.incrementGrade();
	std::cout << "9: " << b_sign << std::endl;
	b_sign.signForm(p);
	std::cout << std::endl;

	std::cout << "10: " << b_execute << std::endl;
	b_execute.executeForm(p);
	b_execute.incrementGrade();
	std::cout << "11: " << b_execute << std::endl;
	b_execute.executeForm(p);
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
}

void robotomy_request_form_tests()
{
	Bureaucrat				b_execute("b_execute", 46);
	Bureaucrat				b_sign("b_sign", 73);
	RobotomyRequestForm	r;
	RobotomyRequestForm	rrf("rrf");
	RobotomyRequestForm	copy(r);

	b_sign.incrementGrade();
	b_sign.signForm(rrf);
	b_sign.decrementGrade();
	std::cout << "12: " << "target of rrf: " << rrf.getTarget() << std::endl;
	std::cout << "13: " << "target of r: " << r.getTarget() << std::endl;
	std::cout << "14: " << "target of copy: " << copy.getTarget() << std::endl;
	std::cout << "15: " << copy << std::endl;
	copy = rrf;
	std::cout << "16: " << "target of copy: " << copy.getTarget() << std::endl;
	std::cout << "17: " << copy << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;

	std::cout << "18: " << r << std::endl;
	std::cout << "19: " << b_sign << std::endl;
	b_execute.executeForm(r);
	b_sign.signForm(r);
	b_sign.incrementGrade();
	std::cout << "20: " << b_sign << std::endl;
	b_sign.signForm(r);
	std::cout << std::endl;

	std::cout << "21: " << b_execute << std::endl;
	b_execute.executeForm(r);
	b_execute.incrementGrade();
	std::cout << "22: " << b_execute << std::endl;
	b_execute.executeForm(r);

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
	Bureaucrat				b_execute("b_execute", 138);
	Bureaucrat				b_sign("b_sign", 146);
	ShrubberyCreationForm	s;
	ShrubberyCreationForm	scf("scf");
	ShrubberyCreationForm	copy(s);

	b_sign.incrementGrade();
	b_sign.signForm(scf);
	b_sign.decrementGrade();
	std::cout << "23: " << "target of scf: " << scf.getTarget() << std::endl;
	std::cout << "24: " << "target of s: " << s.getTarget() << std::endl;
	std::cout << "25: " << "target of copy: " << copy.getTarget() << std::endl;
	std::cout << "26: " << copy << std::endl;
	copy = scf;
	std::cout << "27: " << "target of copy: " << copy.getTarget() << std::endl;
	std::cout << "28: " << copy << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;

	std::cout << "29: " << s << std::endl;
	std::cout << "30: " << b_sign << std::endl;
	b_execute.executeForm(s);
	b_sign.signForm(s);
	b_sign.incrementGrade();
	std::cout << "31: " << b_sign << std::endl;
	b_sign.signForm(s);
	std::cout << std::endl;

	std::cout << "32: " << b_execute << std::endl;
	b_execute.executeForm(s);
	b_execute.incrementGrade();
	std::cout << "33: " << b_execute << std::endl;
	b_execute.executeForm(s);
	
	b_sign.signForm(scf);
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
