#include "PmergeMe.hpp"

void	sort_pairs(std::vector<unsigned>& v, const int element_size)
{
	std::vector<unsigned>::iterator it = v.begin() + element_size - 1;
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

void	insert_every_second_element(std::vector<unsigned>& main_chain, std::vector<unsigned>& v, const int element_size)
{
	std::vector<unsigned>::iterator	itv = v.begin() + (element_size * 2) - 1;

	while (itv < v.end())
	{
		main_chain.insert(main_chain.end(), itv - element_size + 1, itv + 1);
		itv = v.erase(itv - element_size + 1, itv + 1);
		itv += (element_size * 2) - 1;
	}
	main_chain.insert(main_chain.begin(), v.begin(), v.begin() + element_size);
	v.erase(v.begin(), v.begin() + element_size);
}

//this is actually binary search
void	insert_element(std::vector<unsigned>& main_chain, std::vector<unsigned>::const_iterator mc_end, std::vector<unsigned>::const_iterator element_num, const int element_size)
{
	std::vector<unsigned>::iterator	mc_begin = main_chain.begin();
	std::vector<unsigned>::iterator	it;

	while ((mc_end - mc_begin) / element_size > 1)
	{
		it = mc_begin + (((mc_end - mc_begin) / element_size) / 2) * element_size + element_size - 1;
		if (*element_num >= *it)
			mc_begin = it - element_size + 1;
		else
			mc_end = it - element_size + 1;	
	}
	it = mc_begin + (((mc_end - mc_begin) / element_size) / 2) * element_size + element_size - 1;
	if (*element_num >= *it)
		main_chain.insert(it + 1, element_num - element_size + 1, element_num + 1);
	else
		main_chain.insert(it - element_size + 1, element_num - element_size + 1, element_num + 1);
}

void	binary_search_insert(std::vector<unsigned>& main_chain, std::vector<unsigned>& v, const int element_size)
{
	unsigned	jacobsthal_diff[] =  {2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366,
				2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050,
				1398102, 2796202, 5592406, 11184810, 22369622, 44739242, 89478486,
 				178956970, 357913942, 715827882, 1431655766, 2863311530};
	int	jd_i = 0;
	int	itm = (4 * element_size) - 1;
	int	itv;

	while (static_cast<int>(v.size()) >= element_size)
	{
		itv = (jacobsthal_diff[jd_i] * element_size) - 1;
		if (itv >= static_cast<int>(v.size()) || jd_i >= 32)
		{
			itv = v.size() - 1 - (v.size() % element_size); //% element_size in case there are leftover numbers (uneven pairs) from previous recursion
			itm = main_chain.size() + element_size - 1;
		}
		while (itv >= 0)
		{
			insert_element(main_chain, main_chain.begin() + itm - element_size + 1, v.begin() + itv, element_size);
			v.erase(v.begin() + itv - element_size + 1, v.begin() + itv + 1);
			itv -= element_size;
		}
		itm += (jacobsthal_diff[jd_i] * element_size) + (jacobsthal_diff[jd_i + 1] * element_size);
		jd_i++;
	}
}

void	sort_elements(std::vector<unsigned>& v, const int element_size)
{
	std::vector<unsigned>	main_chain;
	main_chain.reserve(v.size());
	
	insert_every_second_element(main_chain, v, element_size); //and first element
	binary_search_insert(main_chain, v, element_size);
	while (!v.empty())
	{
		main_chain.push_back(*v.begin());
		v.erase(v.begin());
	}
	v = main_chain;
}

//Ford-Johnson algorithm (also called merge-insertion sort)
void	fj_vector(std::vector<unsigned>& v, int element_size)
{
	sort_pairs(v, element_size);
	if (v.size() / element_size > 2)
		fj_vector(v, element_size * 2);
	else
		return ;
	sort_elements(v, element_size);
}
