#include "Form.hpp"

static void default_constructor_tests()
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

	bureaucrat.signForm(form);
	std::cout << "7: " << form << std::endl;
	std::cout << "8: " << bureaucrat << std::endl;
	bureaucrat.incrementGrade();
	std::cout << "9: " << bureaucrat << std::endl;
	bureaucrat.signForm(form);
	std::cout << "-----------------------------------------------------" << std::endl;
}

int main()
{
	default_constructor_tests();
	sign_tests();

	Bureaucrat	b("b", 2);
	Form		default_constr;
	Form		copy(default_constr);
	Form		assignment_operator("assigned", 50, 100);

	std::cout << "10: " << "default-constructor:	" << default_constr << std::endl;
	std::cout << "11: " << "copy-constructor:		" << copy << std::endl;
	std::cout << "12: " << "assignment-operator:	" << assignment_operator << std::endl;

	b.signForm(copy);
	std::cout << "13: " << "copy-constructor:		" << copy << std::endl;
	assignment_operator = copy;
	std::cout << "14: " << "assignment-operator:	" << assignment_operator << std::endl;
}
