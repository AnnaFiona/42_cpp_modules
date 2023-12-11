#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <string>

void	SortPairs()
{
	int		arr[] = {3, 4, 1, 2, 5, 6};
	std::vector<int>	v(arr, arr + sizeof(arr) / sizeof(int));

	for (std::vector<int>::iterator it = v.begin(); it < v.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;

	sort_pairs(v, 2);

	for (std::vector<int>::iterator it = v.begin(); it < v.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
}

int main()
{
	SortPairs();
}