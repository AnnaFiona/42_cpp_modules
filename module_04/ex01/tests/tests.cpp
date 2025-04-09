#include "tests.hpp"

int main()
{
	animal_tests();
	cat_tests();
	dog_tests();
	wrong_animal_tests();
	wrong_cat_tests();
	mixed_tests();
	std::cout << "finished" << std::endl;
	return (0);
}