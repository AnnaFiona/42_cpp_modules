# include "../WrongCat.hpp"
# include "../Cat.hpp"
# include "../Dog.hpp"
#include "tests.hpp"

void	mixed_constructor_tests(std::streambuf *filebuf, std::streambuf *coutbuf)
{
	Animal	cow;
	Animal	animal;
	Animal	cowCopy(cow);

	cow.setType("Cow");
	compare(filebuf, coutbuf, "setter:", cow.getType(), "Cow", 'y');
	compare(filebuf, coutbuf, "getter:", cow.getType(), "Cow", 'n');
	compare(filebuf, coutbuf, NULL, cowCopy.getType(), "Animal", 'n');
	compare(filebuf, coutbuf, NULL, animal.getType(), "Animal", 'n');
	cow.makeSound();
	animal.makeSound();
	cowCopy.makeSound();
	animal = cow;
	compare(filebuf, coutbuf, NULL, animal.getType(), "Cow", 'y');
}

void    mixed_tests()
{
	std::cout << "///Mixed-Class tests///" << std::endl;
	constructor_tests_framework(&mixed_constructor_tests, "my_output/mixed.txt", \
									"right_output/mixed.txt", "class messages");
	std::cout << std::endl;
}