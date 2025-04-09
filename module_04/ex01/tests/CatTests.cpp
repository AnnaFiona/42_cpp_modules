# include "../Cat.hpp"
#include "tests.hpp"

void	cat_constructor_tests(std::streambuf *filebuf, std::streambuf *coutbuf)
{
	Cat	bengal;
	Cat	cat;
	Cat	bengalCopy(bengal);

	//ex00
	bengal.setType("bengal");
	compare(filebuf, coutbuf, "ex00:\nsetter:", bengal.getType(), "bengal", 'y');
	compare(filebuf, coutbuf, "getter:", bengal.getType(), "bengal", 'n');
	compare(filebuf, coutbuf, NULL, bengalCopy.getType(), "Cat", 'n');
	compare(filebuf, coutbuf, NULL, cat.getType(), "Cat", 'n');
	bengal.makeSound();
	cat.makeSound();
	bengalCopy.makeSound();
	cat = bengal;
	compare(filebuf, coutbuf, NULL, cat.getType(), "bengal", 'y');

	//ex01
	cat.setIdea("first idea", 0);
	compare(filebuf, coutbuf, "ex01:\nsetter/getter:", cat.getIdea(0), "first idea", 'n');
	for (int x = 0; x < 70; x++)
		cat.setIdea("idea", x);
	compare(filebuf, coutbuf, NULL, cat.getIdea(0), "idea", 'n');
	compare(filebuf, coutbuf, NULL, cat.getIdea(60), "idea", 'n');
	compare(filebuf, coutbuf, NULL, cat.getIdea(70), "", 'n');
	Brain	*b = new Brain();
	cat.setBrain(b);
	compare(filebuf, coutbuf, NULL, cat.getIdea(60), "", 'y');

	for (int x = 0; x < 70; x++)
		cat.setIdea("cat", x);
	bengal = cat;
	compare(filebuf, coutbuf, "deepcopy:", cat.getIdea(60), "cat", 'n');
	Cat	c(bengal);
	compare(filebuf, coutbuf, NULL, c.getIdea(60), "cat", 'n');
	bengal.setIdea("bengal", 0);
	compare(filebuf, coutbuf, NULL, bengal.getIdea(0), "bengal", 'n');
	compare(filebuf, coutbuf, NULL, cat.getIdea(0), "cat", 'n');
	compare(filebuf, coutbuf, NULL, c.getIdea(0), "cat", 'n');
	cat.setIdea("meow", 1);
	compare(filebuf, coutbuf, NULL, bengal.getIdea(1), "cat", 'n');
	compare(filebuf, coutbuf, NULL, cat.getIdea(1), "meow", 'n');
	compare(filebuf, coutbuf, NULL, c.getIdea(1), "cat", 'n');
	c.setIdea("c", 2);
	compare(filebuf, coutbuf, NULL, bengal.getIdea(2), "cat", 'n');
	compare(filebuf, coutbuf, NULL, cat.getIdea(2), "cat", 'n');
	compare(filebuf, coutbuf, NULL, c.getIdea(2), "c", 'y');
}

void	cat_tests()
{
	std::cout << "///Cat-Class tests///" << std::endl;
	constructor_tests_framework(&cat_constructor_tests, "my_output/cat.txt", \
									"right_output/cat.txt", "messages:");
	std::cout << std::endl;
}