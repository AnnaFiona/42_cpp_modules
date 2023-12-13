#include "PmergeMe.hpp"

void	sort_pairs(std::vector<int>& v, const int element_size) //should work
{
	std::vector<int>::iterator it = v.begin() + element_size - 1;
	int		uneven = v.size() % element_size; //in case one of the last recursions were uneven

	if (((v.size() - uneven) / element_size) % 2 == 1)
		uneven += element_size; //in case this recursion is uneven
	while (it < v.end() - uneven) //uneven is there so it doesn't go too far and tries to compare stuff in case it's uneven or one of the last recursions were uneven
	{
		if (*it > *(it + element_size))
			std::swap_ranges(it - element_size + 1, it + 1, it + 1);
		it += element_size * 2;
	}
}


void	insert_every_second_element(std::vector<int>& main_chain, std::vector<int>& v, const int element_size)
{
	std::vector<int>::iterator	itv = v.begin() + (element_size * 2) - 1;

	while (itv < v.end())
	{
		main_chain.insert(main_chain.end(), itv - element_size + 1, itv + 1);
		itv = v.erase(itv - element_size + 1, itv + 1);
		itv += (element_size * 2) - 1;
	}
	main_chain.insert(main_chain.begin(), v.begin(), v.begin() + element_size);
}

//this is actually binary search
void	insert_element(std::vector<int>& main_chain, std::vector<int>::const_iterator mc_end, std::vector<int>::const_iterator element_num, const int element_size)
{
	std::vector<int>::iterator	mc_begin = main_chain.begin();
	std::vector<int>::iterator	it;

	std::cout << "mc_end: " << *mc_end << std::endl;
	std::cout << "element_num: " << *element_num << std::endl;
	std::cout << "length: " << mc_end - mc_begin << std::endl << std::endl;
	while ((mc_end - mc_begin) / element_size > 1)
	{
		it = mc_begin + (((mc_end - mc_begin) / element_size) / 2) * element_size + element_size - 1;
		std::cout << "it: " << *it << std::endl;
		std::cout << "mc_end: " << *mc_end << std::endl;
		std::cout << "mc_begin: " << *mc_begin << std::endl;
		std::cout << "length: " << mc_end - mc_begin << std::endl << std::endl;
		if (*element_num >= *it)
			mc_begin = it - element_size + 1;
		else
			mc_end = it - element_size + 1;		
	}
	it = mc_begin + (((mc_end - mc_begin) / element_size) / 2) * element_size + element_size - 1;
	std::cout << "it2: " << *it << std::endl;
	std::cout << "mc_end: " << *mc_end << std::endl;
	std::cout << "mc_begin: " << *mc_begin << std::endl;
	std::cout << "length: " << mc_end - mc_begin << std::endl << std::endl;
	if (*element_num >= *it)
		main_chain.insert(it + 1, element_num - element_size + 1, element_num + 1);
	else
		main_chain.insert(it - element_size + 1, element_num - element_size + 1, element_num + 1);
}

/* void	binary_search_insert(std::vector<int>& main_chain, std::vector<int>& v, const int element_size)
{
	int	jacobsthal_diff[] =  {2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366,
				2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050,
				1398102, 2796202, 5592406, 11184810, 22369622, 44739242, 89478486,
 				178956970, 357913942, 715827882, 1431655766};
	int	jd_i = 0;
	int	itm = (4 * element_size) - 1; //below 4?
	int	itv;

	while ()
	{
		itv = ((jacobsthal_diff[jd_i] * element_size) - 1);
		if (//uneven)
		while (itv >= 0)
		{
			insert_element(main_chain, main_chain.begin() + itm - element_size + 1, v.begin() + itv, element_size);
			v.erase(v.begin() + (itv - element_size), v.begin() + itv + 1); //?
			itv--;
		}
		itm += (jacobsthal_diff[jd_i] * element_size) + (jacobsthal_diff[jd_i + 1] * (element_size)); //element_size - 1?
		jd_i++;
	}
} */

/* void	sort_elements(std::vector<int>& v, const int element_size)
{
	std::vector<int>	main_chain; //initialize with v.size() because of rezising?
	
	insert_every_second_element(main_chain, v, element_size); //and first element
	binary_search_insert(main_chain, v, element_size);
	//insert uneven elements from previous recursions at end
} */

//Ford-Johnson algorithm (also called merge-insertion sort)
/* void	fj_vector(std::vector<int>& v, int element_size)
{
	sort_pairs(v, element_size);
	if (v.size() / element_size > 2)
		fj_vector(v, element_size * 2);
	else
		return ;
	sort_elements(v, element_size);
} */

/* void	PmergeMe(const char **arr)
{
	print_array(explicit message); //template function
	get_time();
	//fill vector
	fj_vector(vector, recursion number);
	get_time();
	get_time();
	//do algorithm with list
	get_time();
	print_array(explicit message); //sorted	
} */