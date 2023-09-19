#include "Bureaucrat.hpp"

int main()
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
}