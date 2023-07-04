#include "tests.hpp"

void	animal_constructor_tests(std::streambuf *filebuf, std::streambuf *coutbuf)
{
	Animal	cow("Cow");

	compare(filebuf, coutbuf, "getter:", cow.getType(), "Cow", 'y');
	cow.setType("sheep");
	compare(filebuf, coutbuf, "setter:", cow.getType(), "sheep", 'y');
}

void    animal_tests()
{
	constructor_tests_framework(&animal_constructor_tests, "my_output/animal.txt", \
									"right_output/animal.txt", "animal constructors:");
}