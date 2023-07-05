# include "../WrongCat.hpp"
#include "tests.hpp"

void	wrong_cat_constructor_tests(std::streambuf *filebuf, std::streambuf *coutbuf)
{
	WrongCat	bengal;
	WrongCat	cat;
	WrongCat	bengalCopy(bengal);

	bengal.setType("bengal");
	compare(filebuf, coutbuf, "setter:", bengal.getType(), "bengal", 'y');
	compare(filebuf, coutbuf, "getter:", bengal.getType(), "bengal", 'n');
	compare(filebuf, coutbuf, NULL, bengalCopy.getType(), "WrongCat", 'n');
	compare(filebuf, coutbuf, NULL, cat.getType(), "WrongCat", 'n');
	bengal.makeSound();
	cat.makeSound();
	bengalCopy.makeSound();
	cat = bengal;
	compare(filebuf, coutbuf, NULL, cat.getType(), "bengal", 'y');
}

void	wrong_cat_tests()
{
	std::cout << "///WrongCat-Class tests///" << std::endl;
	constructor_tests_framework(&wrong_cat_constructor_tests, "my_output/wrong_cat.txt", \
									"right_output/wrong_cat.txt", "class messages");
	std::cout << std::endl;
}