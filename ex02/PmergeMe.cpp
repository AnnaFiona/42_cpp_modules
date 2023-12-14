#include "PmergeMe.hpp"

void	print_vector(std::vector<unsigned int> v, const std::string explicit_message)
{
	if (!explicit_message.empty())
		std::cout << explicit_message << " ";
	for (std::vector<unsigned int>::const_iterator it = v.begin(); it < v.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
}

void	fill_vector(std::vector<unsigned int>& v, const char **arr)
{
	std::stringstream	stream;
	unsigned int		u;

	for (int i = 1; arr[i]; i++)
	{
		stream << arr[i];
		stream >> u;
		v[i - 1] = u;
		stream.str("");
		stream.clear();
	}
}

std::time_t	get_time()
{
	std::time_t	now;
	
	now = std::time(NULL);
	if (now == -1)
		throw (std::runtime_error("could not get time"));
	return (now);
}

void	PmergeMe(const int argc, const char **arr)
{
	std::vector<unsigned int>	v;
	v.resize(argc - 1);
	//other container
	std::time_t		before_t;
	std::time_t		after_t;

	fill_vector(v, arr);
	print_vector(v, "unsorted: "); //template function
	before_t = get_time();
	fj_vector(v, 1);
	after_t = get_time();
	print_vector(v, "sorted: "); //sorted
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector:	" << before_t - after_t << std::endl; //time doesn't work
//	get_time();
	//do algorithm with list
//	get_time();
	//print time other container
}