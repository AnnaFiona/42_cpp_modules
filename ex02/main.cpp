#include "Array.hpp"
#include <iostream>


/* void	default_constructor() {
	Array<int>	empty();

	std::cout << empty[0] << std::endl;
} */

void	const_arrays() {
	const Array<std::string> const_str(10);
	Array<std::string>	str(10);

	str[2] = "two";
	const_str[3] = "three";
	std::cout << str[2] << std::endl;
	std::cout << const_str[3] << std::endl;

//	const_str = str;
}

void	copy_constructor() {
	std::cout << "///COPY-CONSTRUCTOR///" << std::endl;
	Array<int>	arr(10);
	for (int x = 0; x < 10; x++)
		arr[x] = x;
	Array<int>	copy(arr);

	for (int x = 0; x < 10; x++)
		std::cout << arr[x] << std::endl;
	std::cout << std::endl;
}

void	copy_operator() {
	std::cout << "///COPY-OPERATOR///" << std::endl;
	Array<int>	arr(5);
	Array<int>	copy(10);

	for (int x = 0; x < arr.size(); x++)
		arr[x] = x;
	copy = arr;
	for (int x = 0; x < copy.size(); x++)
		std::cout << "arr: " << arr[x] << "	copy: " << copy[x] << std::endl;
	
	for (int x = 0; x < copy.size(); x++)
		arr[x] += 10;
	for (int x = 0; x < copy.size(); x++)
		std::cout << "arr: " << arr[x] << "	copy: " << copy[x] << std::endl;
	std::cout << std::endl;
}

int	main()
{
	copy_constructor();
	copy_operator();
}