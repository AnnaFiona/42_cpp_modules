#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <string>

/* void	SortPairs()
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
} */

int main()
{
	//SortPairs();

	int		arr[] = {1, 2, 3, 4, 5, 6};
	std::vector<int>	v(arr, arr + sizeof(arr) / sizeof(int));
	std::vector<int>::iterator it = v.begin() + 5;
	std::cout << "1" << std::endl;
	std::cout << *it << std::endl;
	std::cout << "2" << std::endl;
	v.insert(v.begin(), v.begin(), v.begin() + 4);
	std::cout << "3" << std::endl;
	std::vector<int>::iterator i = it;
	std::cout << *i << std::endl;
	std::cout << "4" << std::endl;
	for (std::vector<int>::iterator i = v.begin(); i < v.end(); i++)
		std::cout << *i << ", ";
	std::cout << std::endl;
}