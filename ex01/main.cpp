#include "Form.hpp"

static void constructor_tests()
{
	try {
		Form grade_e_too_high("grade_e_too_high", 0, 150);
	} catch (std::exception& e) {
		std::cout << "1: " << e.what();
	}
	try {
		Form grade_e_too_low("grade_e_too_low", 151, 1);
	} catch (std::exception& e) {
		std::cout << "2: " << e.what();
	}
	std::cout << std::endl;

	try {
		Form grade_s_too_high("grade_s_too_high", 150, 0);
	} catch (std::exception& e) {
		std::cout << "3: " << e.what();
	}
	try {
		Form grade_s_too_low("grade_s_too_low", 1, 151);
	} catch (std::exception& e) {
		std::cout << "4: " << e.what();
	}
	std::cout << std::endl;

	Form grade_in_range_high("grade_in_range_high", 1, 1);
	std::cout << "5: " << grade_in_range_high << std::endl;
	Form grade_in_range_low("grade_in_range_low", 150, 150);
	std::cout << "6: " << grade_in_range_low << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
}

void	sign_tests()
{
	Bureaucrat	bureaucrat("bureaucrat", 43);
	Form		form;

	try {
		bureaucrat.signForm(form);
	} catch (std::exception& e) {
		std::cout << "7: " << e.what();
	}
	std::cout << "8: " << form << std::endl;
	std::cout << "9: " << bureaucrat << std::endl;
	bureaucrat.incrementGrade();
	std::cout << "10: " << bureaucrat << std::endl;
	try {
		bureaucrat.signForm(form);
	} catch (std::exception& e) {
		std::cout << "11: " << e.what();
	}
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
