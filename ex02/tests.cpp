#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <string>

void	print_vector(std::vector<int> v)
{
	for (std::vector<int>::iterator it = v.begin(); it < v.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
}

/* void	insert_element(std::vector<int> main_chain, std::vector<int>::const_iterator mc_end, std::vector<int>::const_iterator element_end, const int element_size)
{
	std::vector<int>::iterator	mc_begin = main_chain.begin();
	std::vector<int>::iterator	it;

	while ((mc_end - mc_begin) / element_size > 1)
	{
		it = mc_begin + ((mc_end - mc_begin) / 2); //?
		if (*element_end >= *it)
			mc_begin = it;
		else
			mc_end = it;		
	}
	if (*element_end >= *it)
		main_chain.insert(it + 1, element_end - element_size + 1, element_end + 1);
	else
		main_chain.insert(it - element_size + 1, element_end - element_size + 1, element_end + 1);
} */


void	insertElements()
{
	std::cout << "////////////////insertElements//////////////" << std::endl;
	int		arrm[] = {1, 3, 5, 6, 8, 9, 0, 11, 12};
	std::vector<int>	main_chain(arrm, arrm + sizeof(arrm) / sizeof(int));
	int		arr[] = {2, 7};
	std::vector<int>	v(arr, arr + sizeof(arr) / sizeof(int));

	print_vector(v);
	print_vector(main_chain);
	insert_element(main_chain, main_chain.end() - 5, v.end() - 1, 1);
	print_vector(main_chain);

	std::cout << "///////////////////////////////////////" << std::endl << std::endl;
}


void	sortPairs()
{
	std::cout << "////////////////sortPairs//////////////" << std::endl;
	int		arr[] = {3, 4, 1, 2, 5, 6};
	std::vector<int>	v(arr, arr + sizeof(arr) / sizeof(int));

	print_vector(v);
	sort_pairs(v, 2);
	print_vector(v);

	std::cout << "///////////////////////////////////////" << std::endl << std::endl;
}

int main()
{
	sortPairs();
	insertElements();

/* 	int		arr[] = {1, 2, 3, 4, 5, 6};
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
	std::cout << std::endl; */
}