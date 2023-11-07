#include <iostream>
#include "Span.hpp"

/* static void	printVector(const std::vector<int> &v)
{
	for (std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); iter++)
		std::cout << *iter << std::endl;
	std::cout << std::endl;
} */
/* static void	printSpan(const Span s, const size_t len)
{
	for (size_t x = 0; x < len; ++x)
		std::cout << x << ": " << s.at(x) << std::endl;
} */
static bool	checkIfSame(const Span a, const Span b, const size_t len)
{
	for (size_t x = 0; x < len; ++x) {
		if (a.at(x) != b.at(x))
			return (false);
	}
	return (true);
}



void	copyConstructor()
{
	std::cout << "///COPY-CONSTRUCTOR///" << std::endl;
	Span	s(10);

	for (int x = 0; x < 5; x++)
		s.addNumber(x);
	Span	copy(s);
	if (checkIfSame(s, copy, 5) == false || s.getN() != copy.getN())
		std::cout << "\033[1;31m FALSE\033[0m" << std::endl;
	else std::cout << "\033[0;32m OK\033[0m" << std::endl;
	
	for (int x = 0; x < 5; x++)
		s.addNumber(9);
	for (int x = 0; x < 5; x++)
		copy.addNumber(7);
	if (checkIfSame(s, copy, 10) != false)
		std::cout << "\033[1;31m FALSE\033[0m" << std::endl;
	else std::cout << "\033[0;32m OK\033[0m" << std::endl;
	std::cout << std::endl;
}

void	copyOperatorOverloader()
{
	std::cout << "///COPY-OPERATOR-OVERLOADER///" << std::endl;
	Span	s(10);
	Span	copy;

	for (int x = 0; x < 5; x++)
		s.addNumber(x);
	copy = s;
	if (checkIfSame(s, copy, 5) == false || s.getN() != copy.getN())
		std::cout << "\033[1;31m FALSE\033[0m" << std::endl;
	else std::cout << "\033[0;32m OK\033[0m" << std::endl;
	
	for (int x = 0; x < 5; x++)
		s.addNumber(9);
	for (int x = 0; x < 5; x++)
		copy.addNumber(7);
	if (checkIfSame(s, copy, 10) != false)
		std::cout << "\033[1;31m FALSE\033[0m" << std::endl;
	else std::cout << "\033[0;32m OK\033[0m" << std::endl;
	std::cout << std::endl;
}

void	emptySpan()
{
	Span	empty;
	std::vector<int>	v(19, 42);

	try {
		empty.addNumber(0);
		std::cout << "\033[1;31m FALSE\033[0m" << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << "\033[0;32m OK\033[0m" << std::endl;
	}
	try {
		empty.addNumber(v.begin(), v.end());
		std::cout << "\033[1;31m FALSE\033[0m" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << "\033[0;32m OK\033[0m" << std::endl;
	}
}

int	main()
{
	copyConstructor();
	copyOperatorOverloader();
	emptySpan();

}

