#include "easyfind.hpp"
#include <iostream>
#include <vector>

int	main()
{
	std::vector<int>	v = {4, 5, 4 , 8 ,8 ,7 ,9 ,6 ,5 ,4 ,1 ,2 ,7 ,6 ,3, 0};
	int					i;

	i = easyfind(v, 1);
	std::cout << i << std::endl;

}