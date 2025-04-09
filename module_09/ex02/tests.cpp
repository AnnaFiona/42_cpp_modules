#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <string>

void	print_vector(std::vector<unsigned> v)
{
	for (std::vector<unsigned>::const_iterator it = v.begin(); it < v.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
}

/* void	sortPairs()
{
	std::cout << "////////////////sortPairs//////////////" << std::endl;
	unsigned		arr[] = {3, 4, 1, 2, 5, 6};
	std::vector<unsigned>	v(arr, arr + sizeof(arr) / sizeof(unsigned));

	print_vector(v);
	sort_pairs(v, 2);
	print_vector(v);

	std::cout << "///////////////////////////////////////" << std::endl << std::endl;
} */
/* 
void	insertElements()
{
	std::cout << "////////////////insertElements//////////////" << std::endl;
	unsigned		arrm[] = {1, 3, 5, 6, 8, 9, 0, 11, 12};
	std::vector<unsigned>	main_chain(arrm, arrm + sizeof(arrm) / sizeof(unsigned));
	unsigned		arr[] = {2, 7};
	std::vector<unsigned>	v(arr, arr + sizeof(arr) / sizeof(unsigned));

	print_vector(v);
	print_vector(main_chain);
	insert_element(main_chain, main_chain.end() - 5, v.end() - 1, 1);
	print_vector(main_chain);

	std::cout << "///////////////////////////////////////" << std::endl << std::endl;
} */

/* void	binarySearchInsert()
{
	std::cout << "///////////////binarySearchInsert///////////////" << std::endl;
	unsigned		arrm[] = {1, 3, 5, 6, 8, 9, 0, 11, 12};
	std::vector<unsigned>	main_chain(arrm, arrm + sizeof(arrm) / sizeof(unsigned));
	unsigned		arr[] = {2, 4};
	std::vector<unsigned>	v(arr, arr + sizeof(arr) / sizeof(unsigned));

	print_vector(v);
	print_vector(main_chain);
	binary_search_insert(main_chain, v, 1);
	print_vector(v);
	print_vector(main_chain);

	std::cout << "///////////////////////////////////////" << std::endl << std::endl;
} */

void	sortElements()
{
	std::cout << "////////////////sortElements//////////////" << std::endl;
	std::vector<unsigned>	main_chain; //initialize with v.size() because of rezising?
	unsigned		arr[] = {2, 3, 5, 7, 1, 4, 6, 10, 9, 11, 8, 12};
	std::vector<unsigned>	v(arr, arr + sizeof(arr) / sizeof(unsigned));

	print_vector(v);
	insert_every_second_element(main_chain, v, 2); //and first element
	print_vector(main_chain);
	print_vector(v);
	binary_search_insert(main_chain, v, 2);
	print_vector(main_chain);
	std::cout << "///////////////////////////////////////" << std::endl << std::endl;
}

/* void	fjVector()
{
	std::cout << "///////////////fjVector////////////////" << std::endl;
	unsigned		arr[] = {14, 97, 92, 75, 98, 46, 94, 89, 22, 15, 52, 90, 74, 55, 58, 100, 65, 27, 62, 86, 78, 82, 59, 53, 25, 96, 38, 13, 67, 54, 36, 72, 60, 93, 10, 64, 42, 16, 44, 17, 26, 2, 87, 21, 6, 9, 31, 5, 11, 32, 79, 83, 0, 73, 24, 12, 76, 71, 50, 34, 41, 81, 1, 70, 69, 61, 99, 68, 48, 20, 88, 91, 85, 29, 66, 19, 95, 28, 30, 3, 43, 4, 33, 56, 40, 47, 77, 35, 8, 39, 18, 80, 45, 23, 84, 63, 7, 49, 37, 57}; //100
	std::vector<unsigned>	v(arr, arr + sizeof(arr) / sizeof(unsigned));

	print_vector(v);
	std::cout << std::endl;
	fj_vector(v, 1);
	print_vector(v);
	for (std::vector<unsigned>::const_iterator it = v.begin(); it < v.end() - 1; it++)
		if (*it > *(it + 1))
			std::cout << "FAIL" << std::endl;
	std::cout << "///////////////////////////////////////" << std::endl << std::endl;
} */


void	print_list(std::list<unsigned> l)
{
	for (std::list<unsigned>::const_iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
}

void	sortPairs()
{
	std::cout << "////////////////sortPairsList//////////////" << std::endl;
	unsigned		arr[] = {4, 3, 1, 2, 6, 5};
	std::vector<unsigned>	v(arr, arr + sizeof(arr) / sizeof(unsigned));
	std::list<unsigned>	l;
	l.insert(l.begin(), v.begin(), v.end());
	
	print_list(l);
	sort_pairs(l, 1);
	sort_pairs(l, 2);
	print_list(l);

	std::cout << "///////////////////////////////////////" << std::endl << std::endl;
}

void	insertElements()
{
	std::cout << "////////////////insertElements//////////////" << std::endl;
	unsigned		arrm[] = {1, 3, 5, 6, 8, 9, 0, 11, 12};
	std::vector<unsigned>	mc(arrm, arrm + sizeof(arrm) / sizeof(unsigned));
	std::list<unsigned>	main_chain;
	main_chain.insert(main_chain.begin(), mc.begin(), mc.end());

	unsigned		arr[] = {2, 7};
	std::vector<unsigned>	v(arr, arr + sizeof(arr) / sizeof(unsigned));
	std::list<unsigned>	l;
	l.insert(l.begin(), v.begin(), v.end());

	print_list(l);
	print_list(main_chain);
	insert_element(main_chain, subtract_it(main_chain.end(), 5), subtract_it(l.end(), 1), 1);
	insert_element(main_chain, subtract_it(main_chain.end(), 5), subtract_it(l.end(), 2), 1);
	print_list(main_chain);

	std::cout << "///////////////////////////////////////" << std::endl << std::endl;
}

void	binarySearchInsert()
{
	std::cout << "///////////////binarySearchInsert///////////////" << std::endl;
	unsigned		arrm[] = {1, 3, 5, 6, 8, 9, 0, 11, 12};
	std::vector<unsigned>	mc(arrm, arrm + sizeof(arrm) / sizeof(unsigned));
	std::list<unsigned>	main_chain;
	main_chain.insert(main_chain.begin(), mc.begin(), mc.end());

	unsigned		arr[] = {2, 4};
	std::vector<unsigned>	v(arr, arr + sizeof(arr) / sizeof(unsigned));
	std::list<unsigned>	l;
	l.insert(l.begin(), v.begin(), v.end());

	print_list(l);
	print_list(main_chain);
	binary_search_insert(main_chain, l, 2);
	print_list(l);
	print_list(main_chain);

	std::cout << "///////////////////////////////////////" << std::endl << std::endl;
}

void	sortElementsList()
{
	std::cout << "////////////////sortElements//////////////" << std::endl;
	unsigned		arr[] = {2, 3, 5, 7, 1, 4, 6, 10, 9, 11, 8, 12};
	std::vector<unsigned>	v(arr, arr + sizeof(arr) / sizeof(unsigned));
	std::list<unsigned>	l;
	l.insert(l.begin(), v.begin(), v.end());
	std::list<unsigned>	main_chain;

	print_list(l);
	insert_every_second_element(main_chain, l, 2); //and first element
	print_list(main_chain);
	print_list(l);
	binary_search_insert(main_chain, l, 2);
	print_list(main_chain);
	std::cout << "///////////////////////////////////////" << std::endl << std::endl;
}

int main()
{
	sortPairs();
	insertElements();
	binarySearchInsert();
	sortElements();
	sortElementsList();
	//fjVector();

}