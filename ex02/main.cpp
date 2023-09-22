#include "Form.hpp"

static void constructor_tests()
{
	try {
		Form grade_e_too_high("grade_e_too_high", 0, 150);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	try {
		Form grade_e_too_low("grade_e_too_low", 151, 1);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << std::endl;

	try {
		Form grade_s_too_high("grade_s_too_high", 150, 0);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	try {
		Form grade_s_too_low("grade_s_too_low", 1, 151);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << "-----------------------------------------------------" << std::endl;
}

void	sign_tests()
{
	Bureaucrat	bureaucrat("bureaucrat", 43);
	Form		form;

	try {
		bureaucrat.signForm(form);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << form << std::endl;
	bureaucrat.incrementGrade();
	std::cout << bureaucrat << std::endl;
	try {
		bureaucrat.signForm(form);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << form << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
}

int main()
{
	constructor_tests();
	sign_tests();

	Bureaucrat	b("b", 2);
	Form		default_constr;
	Form		copy(default_constr);
	Form		assignment_constr("assigned", 50, 100);

	std::cout << "default-constructor:	" << default_constr << std::endl;
	std::cout << "copy-constructor:	" << copy << std::endl;
	std::cout << "assignment-constructor:	" << assignment_constr << std::endl;
	try {
		b.signForm(assignment_constr);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << "assignment-constructor:	" << assignment_constr << std::endl;
	copy = assignment_constr;
	std::cout << "copy-constructor:	" << copy << std::endl;
}

/* int main()
{
	Bureaucrat decrement_too_low("decrement_too_low", 150);
	std::cout << decrement_too_low << std::endl;
	try {
		decrement_too_low.decrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << decrement_too_low << std::endl << std::endl;


	Bureaucrat increment_too_high("increment_too_high", 1);
	std::cout << increment_too_high << std::endl;
	try {
		increment_too_high.incrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << increment_too_high << std::endl << std::endl;


	try {
		Bureaucrat init_too_low("init_too_low", 250);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << std::endl;


	try {
		Bureaucrat init_too_high("init_too_high", -42);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl;
} */