#include "PmergeMe.hpp"

void	print_arr(const char **arr, const std::string explicit_message)
{
	size_t i = 1;

	if (!explicit_message.empty())
		std::cout << explicit_message << " ";
	while (arr[i + 1])
		std::cout << arr[i++] << ", ";
	std::cout << arr[i] << std::endl;
}

void	print_vector(std::vector<unsigned> v, const std::string explicit_message)
{
	std::vector<unsigned>::const_iterator it = v.begin();

	if (!explicit_message.empty())
		std::cout << explicit_message << " ";
	while ( it < v.end() - 1)
		std::cout << *it++ << ", ";
	std::cout << *it << std::endl;
}

void	print_list(std::list<unsigned> l, const std::string explicit_message)
{
	if (!explicit_message.empty())
		std::cout << explicit_message << " ";
	for (std::list<unsigned>::const_iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
}

void	fill_vector(std::vector<unsigned>& v, const char **arr)
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

void	fill_list(std::list<unsigned>& l, const char **arr)
{
	std::stringstream	stream;
	unsigned int		u;

	for (int i = 1; arr[i]; i++)
	{
		stream << arr[i];
		stream >> u;
		l.push_back(u);
		stream.str("");
		stream.clear();
	}
}

int	get_time()
{
	struct timeval	now;

	if (gettimeofday(&now, NULL) == - 1)
		throw (std::runtime_error("could not get time"));
	return (now.tv_usec);
}

void	PmergeMe(const int argc, const char **arr)
{
	std::vector<unsigned>	v;
	v.resize(argc - 1);
	std::list<unsigned>		l;
	int	before_t;
	int	after_t;

	print_arr(arr, "unsorted: ");
	before_t = get_time();
	fill_vector(v, arr);
	fj_vector(v, 1);
	after_t = get_time();
	print_vector(v, "sorted: ");
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << after_t - before_t << " microseconds" << std::endl;
	before_t = get_time();
	fill_list(l, arr);
	fj_list(l, 1);
	after_t = get_time();
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::list:   " << after_t - before_t << " microseconds" << std::endl;
	print_list(l, "list: ");
}