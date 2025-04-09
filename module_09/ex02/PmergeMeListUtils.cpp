#include "PmergeMe.hpp"
int	size(std::list<unsigned> l)
{
	int	size = 0;

	for (std::list<unsigned>::const_iterator it = l.begin(); it != l.end(); it++)
		size++;
	return (size);
}

int	get_working_size(std::list<unsigned>::const_iterator begin, std::list<unsigned>::const_iterator end)
{
	int	size = 0;

	while (begin != end)
	{
		size++;
		begin++;
	}
	return (size);
}

std::list<unsigned>::const_iterator	subtract_it(std::list<unsigned>::const_iterator it, int subtract)
{
	for (int i = subtract; i > 0; i--)
		it--;
	return (it);
}
std::list<unsigned>::iterator	subtract_it(std::list<unsigned>::iterator it, int subtract)
{
	for (int i = subtract; i > 0; i--)
		it--;
	return (it);
}

std::list<unsigned>::const_iterator	add_it(std::list<unsigned>::const_iterator it, int add)
{
	for (int i = 0; i < add; i++)
		it++;
	return (it);
}
std::list<unsigned>::iterator	add_it(std::list<unsigned>::iterator it, int add)
{
	for (int i = 0; i < add; i++)
		it++;
	return (it);
}
