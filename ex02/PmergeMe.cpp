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

void	binary_search_insert(std::vector<int>& main_chain, std::vector<int>& v, const int element_size)
{
	int	jacobsthal_diff[] =  {2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366,
				2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050,
				1398102, 2796202, 5592406, 11184810, 22369622, 44739242, 89478486,
 				178956970, 357913942, 715827882, 1431655766};
	int	jd_i = 0;
	int	diff = 0;
	std::vector<int>::iterator	itm = main_chain.begin() + (element_size * 3) - 1;
	std::vector<int>::iterator	itv = v.begin() + element_size - 1;

	while (itv < v.end())
	{
		diff = 0;
			while (diff < jacobsthal_diff[jd_i])
			{
				//insert num(main_chain, )
			}
		jd_i++;
	}
}

void	sort_elements(std::vector<int>& v, const int element_size)
{
	std::vector<int>	main_chain;
	

	insert_every_second_element(main_chain, v, element_size); //and first element
	//insert rest of elements using binary search and jacobsthal-number-difference

	//insert uneven elements from previous recursions at end
}

//Ford-Johnson algorithm (also called merge-insertion sort)
void	fj_vector(std::vector<int>& v, int element_size)
{
	sort_pairs(v, element_size);
	if (v.size() / element_size > 2)
		fj_vector(v, element_size * 2);
	else
		return ;
	sort_elements(v, element_size);
}

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