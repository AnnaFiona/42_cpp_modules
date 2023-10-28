#include "Array.hpp"
#include <iostream>


void	exception_handling() {
	std::cout << "///EXCEPTION-HANDLING///" << std::endl;
	Array<char>	arr(10);
	Array<int>	empty;

	try {
		std::cout << empty[0] << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	try {
		std::cout << arr[11] << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	try {
		std::cout << arr[-4] << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	const_arrays() {
//	std::cout << "///CONST-ARRAYS///" << std::endl;
	const Array<int>	const_str(10);
	Array<int>			str(10);

	str[2] = 2;
//	const_str[3] = 3;
//	const_str = str;
//	std::cout << std::endl;
}

void	copy_constructor() {
	std::cout << "///COPY-CONSTRUCTOR///" << std::endl;
	Array<char>	arr(10);
	for (unsigned x = 0; x < arr.size(); x++)
		arr[x] = x + 65;
	Array<char>	copy(arr);

	for (unsigned x = 0; x < copy.size(); x++)
		std::cout << "arr: " << arr[x] << "	copy: " << copy[x] << std::endl;
	std::cout << std::endl;

	for (unsigned x = 0; x < arr.size(); x++)
		arr[x] += 10;
	for (unsigned x = 0; x < copy.size(); x++)
		copy[x] += 32;

	for (unsigned x = 0; x < copy.size(); x++)
		std::cout << "arr: " << arr[x] << "	copy: " << copy[x] << std::endl;
	std::cout << std::endl;
}

void	copy_operator() {
	std::cout << "///COPY-OPERATOR///" << std::endl;
	Array<int>	arr(5);
	Array<int>	copy;

	for (unsigned x = 0; x < arr.size(); x++)
		arr[x] = x;
	copy = arr;
	for (unsigned x = 0; x < copy.size(); x++)
		std::cout << "arr: " << arr[x] << "	copy: " << copy[x] << std::endl;
	
	for (unsigned x = 0; x < arr.size(); x++)
		arr[x] += 10;
	for (unsigned x = 0; x < copy.size(); x++)
		copy[x] -= 10;
	std::cout << std::endl;
	for (unsigned x = 0; x < copy.size(); x++)
		std::cout << "arr: " << arr[x] << "	copy: " << copy[x] << std::endl;
	std::cout << std::endl;
}

int	main()
{
	exception_handling();
	const_arrays();
	copy_constructor();
	copy_operator();
}