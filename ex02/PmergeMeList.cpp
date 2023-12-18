#include "PmergeMe.hpp"

void	sort_pairs(std::list<unsigned>& l, const int element_size)
{
	std::list<unsigned>::iterator it = add_it(l.begin(), element_size - 1);
	int		uneven = size(l) % element_size; //in case one of the last recursions were uneven

	if (size(l) / element_size < 2)
		return ;
	if (((size(l) - uneven) / element_size) % 2 == 1)
		uneven += element_size; //in case this recursion is uneven
	while (it != subtract_it(l.end(), uneven)) //uneven is there so it doesn't go too far and tries to compare stuff in case it's uneven or one of the last recursions were uneven
	{
		if (*it > *add_it(it, element_size))
			std::swap_ranges(subtract_it(it, element_size - 1), add_it(it, 1), add_it(it, 1));
		for (int i = 0; i < element_size * 2; i++)
			if (++it == subtract_it(l.end(), uneven))
				break ;
	}
}

void	insert_every_second_element(std::list<unsigned>& main_chain, std::list<unsigned>& l, const int element_size)
{
	std::list<unsigned>::iterator	itl = add_it(l.begin(), (element_size * 2) - 1);
	std::list<unsigned>::iterator	temp;

	while (itl != l.end())
	{
		/* main_chain.insert(main_chain.end(), subtract_it(itl, element_size - 1), add_it(itl, 1));
		itl = l.erase(subtract_it(itl, element_size - 1), add_it(itl, 1)); */
		temp = add_it(itl, 1);
		main_chain.splice(main_chain.end(), l, subtract_it(itl, element_size - 1), temp);
		itl = temp;
		for (int i = 0; i < (element_size * 2) - 1; i++)
		{
			if (itl == l.end())
				break ;
			itl++;
		}
	}
	/* main_chain.insert(main_chain.begin(), l.begin(), add_it(l.begin(), element_size));
	l.erase(l.begin(), add_it(l.begin(), element_size)); */
	main_chain.splice(main_chain.begin(), l, l.begin(), add_it(l.begin(), element_size));
}

//this is actually binary search
void	insert_element(std::list<unsigned>& main_chain, std::list<unsigned>::const_iterator mc_end, std::list<unsigned>::const_iterator element_num, const int element_size)
{
	std::list<unsigned>::iterator	mc_begin = main_chain.begin();
	std::list<unsigned>::iterator	it;

	while (get_working_size(mc_begin, mc_end) / element_size > 1)
	{
		it = add_it(mc_begin, ((get_working_size(mc_begin, mc_end) / element_size) / 2) * element_size + element_size - 1);
		if (*element_num >= *it)
			mc_begin = subtract_it(it, element_size - 1);
		else
			mc_end = subtract_it(it, element_size - 1);	
	}
	it = add_it(mc_begin, ((get_working_size(mc_begin, mc_end) / element_size) / 2) * element_size + element_size - 1);
	if (*element_num >= *it)
		main_chain.insert(add_it(it, 1), subtract_it(element_num, element_size - 1), add_it(element_num, 1));
	else
		main_chain.insert(subtract_it(it, element_size - 1), subtract_it(element_num, element_size - 1), add_it(element_num, 1));
}

void	binary_search_insert(std::list<unsigned>& main_chain, std::list<unsigned>& l, const int element_size)
{
	unsigned	jacobsthal_diff[] =  {2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366,
				2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050,
				1398102, 2796202, 5592406, 11184810, 22369622, 44739242, 89478486,
 				178956970, 357913942, 715827882, 1431655766, 2863311530};
	int	jd_i = 0;
	int	itm = (4 * element_size) - 1;
	int	itl;

	while (static_cast<int>(size(l)) >= element_size)
	{
		itl = (jacobsthal_diff[jd_i] * element_size) - 1;
		if (itl >= static_cast<int>(size(l)) || jd_i >= 32)
		{
			itl = size(l) - 1 - (size(l) % element_size); //% element_size in case there are leftover numbers (uneven pairs) from previous recursion
			itm = size(main_chain) + element_size - 1;
		}
		while (itl >= 0)
		{
			insert_element(main_chain, add_it(main_chain.begin(), itm - element_size + 1), add_it(l.begin(), itl), element_size);
			l.erase(add_it(l.begin(), itl - element_size + 1), add_it(l.begin(), itl + 1));
			itl -= element_size;
		}
		print_list(main_chain, "		m: ");
		print_list(l, "		l: ");
		itm += (jacobsthal_diff[jd_i] * element_size) + (jacobsthal_diff[jd_i + 1] * element_size);
		jd_i++;
	}
}

void	sort_elements(std::list<unsigned>& l, const int element_size)
{
	std::list<unsigned>	main_chain;
	
	insert_every_second_element(main_chain, l, element_size); //and first element
	binary_search_insert(main_chain, l, element_size);
	while (!l.empty())
	{
		main_chain.push_back(*l.begin());
		l.erase(l.begin());
	}
	l = main_chain;
}

//Ford-Johnson algorithm (also called merge-insertion sort)
void	fj_list(std::list<unsigned>& l, int element_size)
{
	sort_pairs(l, element_size);
	std::cout << element_size;
	print_list(l, "blist: ");
	if (size(l) / element_size > 2) // * 2?
		fj_list(l, element_size * 2);
	else
		return ;
	sort_elements(l, element_size);
	std::cout << element_size;
	print_list(l, "list: ");
}
