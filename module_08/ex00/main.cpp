#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <limits>
#include <deque>
#include <list>


static void	numInVector()
{
	int					arr[16] = {4, 5, -4 , std::numeric_limits<int>::max() ,8 ,7 ,9 ,6 ,5 ,4 ,1 ,2 , std::numeric_limits<int>::min(),6 ,3, 0};
	int					len = sizeof(arr) / sizeof(arr[0]);
	std::vector<int>	v(arr, arr + len); 

	std::cout << "///numInVector///" << std::endl;
	check(1, v, 5);
	check(2, v, -4);
	check(3, v, 0);
	check(4, v, std::numeric_limits<int>::max());
	check(5, v, std::numeric_limits<int>::min());
	std::cout << std::endl;
}

static void	numInDeque()
{
	int					arr[16] = {4, 5, -4 , std::numeric_limits<int>::max() ,8 ,7 ,9 ,6 ,5 ,4 ,1 ,2 , std::numeric_limits<int>::min(),6 ,3, 0};
	int					len = sizeof(arr) / sizeof(arr[0]);
	std::deque<int>		d(arr, arr + len); 

	std::cout << "///numInDeque///" << std::endl;
	check(1, d, 5);
	check(2, d, -4);
	check(3, d, 0);
	check(4, d, std::numeric_limits<int>::max());
	check(5, d, std::numeric_limits<int>::min());
	std::cout << std::endl;
}

static void	numInList()
{
	int					arr[16] = {4, 5, -4 , std::numeric_limits<int>::max() ,8 ,7 ,9 ,6 ,5 ,4 ,1 ,2 , std::numeric_limits<int>::min(),6 ,3, 0};
	int					len = sizeof(arr) / sizeof(arr[0]);
	std::list<int>	l(arr, arr + len); 

	std::cout << "///numInList///" << std::endl;
	check(1, l, 5);
	check(2, l, -4);
	check(3, l, 0);
	check(4, l, std::numeric_limits<int>::max());
	check(5, l, std::numeric_limits<int>::min());
	std::cout << std::endl;
}

static void	numNotInContainer()
{
	int					arr[]  = {-8, 5, 77, 9, 42, 0, -2, 84};
	int					len = sizeof(arr) / sizeof(arr[0]);
	std::vector<int>	v(arr, arr + len);
	std::deque<int>		d(arr, arr + len);
	std::list<int>		l(arr, arr + len);

	std::cout << "///numNotInContainer///" << std::endl;
	check(1, v, 1);
	check(2, d, 1);
	check(3, l, 1);
	std::cout << std::endl;
}

static void	emptyContainer()
{
	std::vector<int>	v;
	std::deque<int>		d;
	std::list<int>		l;

	std::cout << "///emptyContainer///" << std::endl;
	check(1, v, 1);
	check(2, d, 2);
	check(3, l, 3);
	std::cout << std::endl;
}

int	main()
{
	numInVector();
	numInList();
	numInDeque();
	numNotInContainer();
	emptyContainer();
}