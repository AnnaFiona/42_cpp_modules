#include "PmergeMe.hpp"

void	print_vector(std::vector<unsigned int> v, const std::string explicit_message)
{
	if (!explicit_message.empty())
		std::cout << explicit_message << " ";
	for (std::vector<unsigned int>::const_iterator it = v.begin(); it < v.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
}

void	fill_vector(std::vector<unsigned int> v, const char **arr)
{
	std::stringstream	stream;
	unsigned int		u;

	for (int i = 0; arr[i]; i++)
	{
		
		v.push_back(arr[i]);
		stream.clear() //?

	}
}

void	PmergeMe(const int argc, const char **arr)
{
	std::vector<unsigned int>	v;
	v.resize(argc);
	//other container

	print_vector(v, ""); //template function
/* 	get_time();
	//fill vector */
	fj_vector(v, 1);
/* 	get_time();
	get_time();
	//do algorithm with list
	get_time(); */
	print_vector(v, ""); //sorted	
}