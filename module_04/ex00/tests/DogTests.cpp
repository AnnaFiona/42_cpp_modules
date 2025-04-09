# include "../Dog.hpp"
#include "tests.hpp"

void	dog_constructor_tests(std::streambuf *filebuf, std::streambuf *coutbuf)
{
	Dog	beagle;
	Dog	dog;
	Dog	beagleCopy(beagle);

	beagle.setType("beagle");
	compare(filebuf, coutbuf, "setter:", beagle.getType(), "beagle", 'y');
	compare(filebuf, coutbuf, "getter:", beagle.getType(), "beagle", 'n');
	compare(filebuf, coutbuf, NULL, beagleCopy.getType(), "Dog", 'n');
	compare(filebuf, coutbuf, NULL, dog.getType(), "Dog", 'n');
	beagle.makeSound();
	dog.makeSound();
	beagleCopy.makeSound();
	dog = beagle;
	compare(filebuf, coutbuf, NULL, dog.getType(), "beagle", 'y');
}

void	dog_tests()
{
	std::cout << "///Dog-Class tests///" << std::endl;
	constructor_tests_framework(&dog_constructor_tests, "my_output/dog.txt", \
									"right_output/dog.txt", "messages:");
	std::cout << std::endl;
}