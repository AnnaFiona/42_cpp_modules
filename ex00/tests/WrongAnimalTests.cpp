# include "../WrongAnimal.hpp"
#include "tests.hpp"

void	wrong_animal_constructor_tests(std::streambuf *filebuf, std::streambuf *coutbuf)
{
	WrongAnimal	cow;
	WrongAnimal	animal;
	WrongAnimal	cowCopy(cow);

	cow.setType("Cow");
	compare(filebuf, coutbuf, "setter:", cow.getType(), "Cow", 'y');
	compare(filebuf, coutbuf, "getter:", cow.getType(), "Cow", 'n');
	compare(filebuf, coutbuf, NULL, cowCopy.getType(), "WrongAnimal", 'n');
	compare(filebuf, coutbuf, NULL, animal.getType(), "WrongAnimal", 'n');
	cow.makeSound();
	animal.makeSound();
	cowCopy.makeSound();
	animal = cow;
	compare(filebuf, coutbuf, NULL, animal.getType(), "Cow", 'y');
}

void	wrong_animal_tests()
{
	std::cout << "///WrongWrongAnimal-Class tests///" << std::endl;
	constructor_tests_framework(&wrong_animal_constructor_tests, "my_output/wrong_animal.txt", \
									"right_output/wrong_animal.txt", "class messages");
	std::cout << std::endl;
}