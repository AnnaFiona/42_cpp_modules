# include "../Animal.hpp"
#include "tests.hpp"

void	animal_constructor_tests(/* std::streambuf *filebuf, std::streambuf *coutbuf */)
{
/* 	Animal	cow;
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
	compare(filebuf, coutbuf, NULL, animal.getType(), "Cow", 'y'); */

}

void    animal_tests()
{
	std::cout << "///Animal-Class tests///" << std::endl;
	/* constructor_tests_framework(&animal_constructor_tests, "my_output/animal.txt", \
									"right_output/animal.txt", "messages:"); */
	std::cout << "won't work because Animal class is not instantiable" << std::endl;
	std::cout << std::endl;
}