#include "iter.hpp"
#include <iostream>

void	add(int &i)
{
	i++;
}

int main()
{
	int	arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	iter<int>(arr, 12, add);
	for (size_t x = 0; x < 10; x++)
		std::cout << arr[x] << std::endl;
}