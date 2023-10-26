#include "iter.hpp"
#include <iostream>

int		match(const int& x)
{
	if (x == 42)
		std::cout << "match" << std::endl;
	return (x);
}

void	str_add(std::string& str)
{
	str = "twenty" + str;
}



void	test_null()
{
	try {
		iter<int>(NULL, 6, add<int>);
	} catch (std::exception& e) {
		std::cout << "what: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_int_arr()
{
	int	arr[5] = {0, 1, 2, 3, 4};

	iter<int>(arr, 5, add<int>);
	for (size_t x = 0; x < 5; x++)
		std::cout << arr[x] << std::endl;
	std::cout << std::endl;
}

void	test_const_int_arr()
{
	const int	arr[10] = {0, 1, 2, 42, 4, 5, 42, 7, 8, 9};

	iter<const int>(arr, 10, match);
	std::cout << std::endl;
}

void test_string_arr()
{
	std::string	arr[] = {"one", "two", "three", "four", "five"};

	iter<std::string>(arr, 5, str_add);
	for (size_t x = 0; x < 5; x++)
		std::cout << arr[x] << std::endl;
	std::cout << std::endl;
}


int main()
{
	test_null();
	test_int_arr();
	test_const_int_arr();
 	test_string_arr();
}