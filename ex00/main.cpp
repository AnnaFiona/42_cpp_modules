#include "Bureaucrat.hpp"

int main()
{
//decrement_grade_too_low
	Bureaucrat decrement_too_low;
	std::cout << "0: "  << decrement_too_low << std::endl;
	try {
		decrement_too_low.decrementGrade();
	} catch (std::exception& e) {
		std::cout << "1: " << e.what();
	}
	std::cout << "2: " << decrement_too_low << std::endl;
//increment_grade_too_high
	Bureaucrat increment_too_high("increment_too_high", 1);
	std::cout << "3: " << increment_too_high << std::endl;
	try {
		increment_too_high.incrementGrade();
	} catch (std::exception& e) {
		std::cout << "4: " << e.what();
	}
	std::cout << "5: " << increment_too_high << std::endl << std::endl;


//init_grade_too_high
	try {
		Bureaucrat init_too_high("init_too_high", 0);
	} catch (std::exception& e) {
		std::cout << "6: " << e.what();
	};
//init_grade_too_low
	try {
		Bureaucrat init_too_low("init_too_low", 151);
	} catch (std::exception& e) {
		std::cout << "7: " << e.what();
	}
	std::cout << std::endl;


//assignment_operator
	Bureaucrat	assigned("assigned", 42);
	std::cout << "10: " << assigned << std::endl;
	try {
		assigned = increment_too_high;
	} catch (std::exception& e) {
		std::cout << "11: " << e.what();
	}
	std::cout << "12: " << assigned << std::endl << std::endl;


//copy-constructor
	Bureaucrat	copy(assigned);
	std::cout << "13: " << copy << std::endl;
}