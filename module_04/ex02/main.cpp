#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal	**animals = new Animal*[10];
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	//Animal a; - won't work because Animal class is not instantiable
	
	for (int x = 0; x < 5; x++)
		animals[x] = new Dog;
	for (int x = 5; x < 10; x++)
		animals[x] = new Cat;

	for (int x = 0; x < 10; x++)
		animals[x]->makeSound();

	delete j;//should not create a leak
	delete i;
	for (int x = 0; x < 10; x++)
		delete animals[x];
	delete [] animals;
	return (0);
}