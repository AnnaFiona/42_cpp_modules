# include "../Dog.hpp"
#include "tests.hpp"

void	dog_constructor_tests(std::streambuf *filebuf, std::streambuf *coutbuf)
{
	Dog	beagle;
	Dog	dog;
	Dog	beagleCopy(beagle);

	beagle.setType("beagle");
	compare(filebuf, coutbuf, "ex00:\nsetter:", beagle.getType(), "beagle", 'y');
	compare(filebuf, coutbuf, "getter:", beagle.getType(), "beagle", 'n');
	compare(filebuf, coutbuf, NULL, beagleCopy.getType(), "Dog", 'n');
	compare(filebuf, coutbuf, NULL, dog.getType(), "Dog", 'n');
	beagle.makeSound();
	dog.makeSound();
	beagleCopy.makeSound();
	dog = beagle;
	compare(filebuf, coutbuf, NULL, dog.getType(), "beagle", 'y');

	//ex01
	dog.setIdea("first idea", 0);
	compare(filebuf, coutbuf, "ex01:\nsetter/getter:", dog.getIdea(0), "first idea", 'n');
	for (int x = 0; x < 70; x++)
		dog.setIdea("idea", x);
	compare(filebuf, coutbuf, NULL, dog.getIdea(0), "idea", 'n');
	compare(filebuf, coutbuf, NULL, dog.getIdea(60), "idea", 'n');
	compare(filebuf, coutbuf, NULL, dog.getIdea(70), "", 'n');
	Brain	*b = new Brain();
	dog.setBrain(b);
	compare(filebuf, coutbuf, NULL, dog.getIdea(60), "", 'y');

	for (int x = 0; x < 70; x++)
		dog.setIdea("dog", x);
	beagle = dog;
	compare(filebuf, coutbuf, "deepcopy:", dog.getIdea(60), "dog", 'n');
	Dog	d(beagle);
	compare(filebuf, coutbuf, NULL, d.getIdea(60), "dog", 'n');
	beagle.setIdea("beagle", 0);
	compare(filebuf, coutbuf, NULL, beagle.getIdea(0), "beagle", 'n');
	compare(filebuf, coutbuf, NULL, dog.getIdea(0), "dog", 'n');
	compare(filebuf, coutbuf, NULL, d.getIdea(0), "dog", 'n');
	dog.setIdea("meow", 1);
	compare(filebuf, coutbuf, NULL, beagle.getIdea(1), "dog", 'n');
	compare(filebuf, coutbuf, NULL, dog.getIdea(1), "meow", 'n');
	compare(filebuf, coutbuf, NULL, d.getIdea(1), "dog", 'n');
	d.setIdea("d", 2);
	compare(filebuf, coutbuf, NULL, beagle.getIdea(2), "dog", 'n');
	compare(filebuf, coutbuf, NULL, dog.getIdea(2), "dog", 'n');
	compare(filebuf, coutbuf, NULL, d.getIdea(2), "d", 'y');
}

void	dog_tests()
{
	std::cout << "///Dog-Class tests///" << std::endl;
	constructor_tests_framework(&dog_constructor_tests, "my_output/dog.txt", \
									"right_output/dog.txt", "messages:");
	std::cout << std::endl;
}