#include "Bureaucrat.hpp"

int main()
{
//decrement_grade_too_low
	Bureaucrat decrement_too_low;
	std::cout << decrement_too_low << std::endl;
	try {
		decrement_too_low.decrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << decrement_too_low << std::endl;
//increment_grade_too_high
	Bureaucrat increment_too_high("increment_too_high", 1);
	std::cout << increment_too_high << std::endl;
	try {
		increment_too_high.incrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << increment_too_high << std::endl << std::endl;


//init_grade_too_high
	try {
		Bureaucrat init_too_high("init_too_high", -42);
	} catch (std::exception& e) {
		std::cout << e.what();
	};
//init_grade_too_low
	try {
		Bureaucrat init_too_low("init_too_low", 250);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << std::endl;


//copy-constructor_grade_too_high
	try {
		Bureaucrat copy_too_high(increment_too_high);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
//copy-constructor_grade_too_low
	try {
		Bureaucrat copy_too_low(decrement_too_low);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << std::endl;


//assignment_operator_grade_too_high
	Bureaucrat	assigned("assigned", 42);
	std::cout << assigned << std::endl;
	try {
		assigned = increment_too_high;
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << assigned << std::endl;
//assignment_operator_grade_too_low
	try {
		assigned = decrement_too_low;
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << assigned << std::endl << std::endl;	

}