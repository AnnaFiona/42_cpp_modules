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

/* std::time_t	get_time()
{
	std::time_t	now;
	
	now = std::time(NULL);
	if (now == -1)
		throw (std::runtime_error("could not get time"));
	return (now);
} */

int	get_time()
{
	struct timeval	now;

	if (gettimeofday(&now, NULL) == - 1)
		throw (std::runtime_error("could not get time"));
	return (now.tv_usec);
}

void	PmergeMe(const int argc, const char **arr)
{
	std::vector<unsigned int>	v;
	v.resize(argc - 1);
	//other container
	int	before_t;
	int	after_t;

	fill_vector(v, arr);
	print_vector(v, "unsorted: "); //template function
	before_t = get_time();
	fj_vector(v, 1);
	after_t = get_time();
	print_vector(v, "sorted: "); //sorted
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector:	" << after_t - before_t << " microseconds" << std::endl; //time doesn't work
//	get_time();
	//do algorithm with list
//	get_time();
	//print time other container
}