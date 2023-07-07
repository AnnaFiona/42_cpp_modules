# include "../Cat.hpp"
#include "tests.hpp"

void	cat_constructor_tests(std::streambuf *filebuf, std::streambuf *coutbuf)
{
	Cat	bengal;
	Cat	cat;
	Cat	bengalCopy(bengal);

	bengal.setType("bengal");
	compare(filebuf, coutbuf, "setter:", bengal.getType(), "bengal", 'y');
	compare(filebuf, coutbuf, "getter:", bengal.getType(), "bengal", 'n');
	compare(filebuf, coutbuf, NULL, bengalCopy.getType(), "Cat", 'n');
	compare(filebuf, coutbuf, NULL, cat.getType(), "Cat", 'n');
	bengal.makeSound();
	cat.makeSound();
	bengalCopy.makeSound();
	cat = bengal;
	compare(filebuf, coutbuf, NULL, cat.getType(), "bengal", 'y');
}

void	cat_tests()
{
	std::cout << "///Cat-Class tests///" << std::endl;
	constructor_tests_framework(&cat_constructor_tests, "my_output/cat.txt", \
									"right_output/cat.txt", "messages:");
	std::cout << std::endl;
}