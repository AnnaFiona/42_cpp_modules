#include <iostream>
#include "Span.hpp"

/* static void	printVector(const std::vector<int> &v)
{
	for (std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); iter++)
		std::cout << *iter << std::endl;
	std::cout << std::endl;
} */
static void	printSpan(const Span s, const size_t len)
{
	for (size_t x = 0; x < len; ++x)
		std::cout << s.at(x) << ", ";
	std::cout << std::endl;
}
static bool	checkIfSame(const Span a, const Span b, const size_t len)
{
	for (size_t x = 0; x < len; ++x) {
		if (a.at(x) != b.at(x))
			return (false);
	}
	return (true);
}
static Span	getRandSpan(const int n, const int modulo)
{
	std::vector<int> v(n);
	Span	s(n);

	srand(time(0));

	for (int i = 0; i < n; i++)
		v.at(i) = rand() % modulo + 1;
	s.addNumber(v.begin(), v.end());
	return (s);
}



void	copyConstructor()
{
	std::cout << "\033[0;33m///COPY-CONSTRUCTOR///\033[0m" << std::endl;
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
	std::cout << "\033[0;33m///COPY-OPERATOR-OVERLOADER///\033[0m" << std::endl;
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
	std::cout << "\033[0;33m///EMPTY-SPAN///\033[0m" << std::endl;
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
	try {
		empty.longestSpan();
		std::cout << "\033[1;31m FALSE\033[0m" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << "\033[0;32m OK\033[0m" << std::endl;
	}
	try {
		empty.shortestSpan();
		std::cout << "\033[1;31m FALSE\033[0m" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << "\033[0;32m OK\033[0m" << std::endl;
	}
	std::cout << std::endl;
}

void	addOneNumber()
{
	std::cout << "\033[0;33m///ADD-ONE-NUMBER///\033[0m" << std::endl;
	Span	span(3);

	span.addNumber(1);
	span.addNumber(-2);
	span.addNumber(3);
	if (span.at(0) == 1 || span.at(1) == -2 || span.at(2) == 3)
		std::cout << "\033[0;32m OK\033[0m" << std::endl;
	else std::cout << "\033[1;31m FALSE\033[0m" << std::endl;

	try {
		span.addNumber(4);
		std::cout << "\033[1;31m FALSE\033[0m" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << "\033[0;32m OK\033[0m" << std::endl;
	}

	std::cout << std::endl;
}

void	addMultipleNumber()
{
	std::cout << "\033[0;33m///ADD-MULTIPLE-NUMBER///\033[0m" << std::endl;
	Span				span(3);
	std::vector<int>	v_too_many(4);
	std::vector<int>	v(3);

	v_too_many.at(0) = 1; v.at(0) = 1;
	v_too_many.at(1) = -2; v.at(1) = -2;
	v_too_many.at(2) = 3; v.at(2) = 3;
	v_too_many.at(3) = 4;

	try {
		span.addNumber(v_too_many.begin(), v_too_many.end());
		std::cout << "\033[1;31m FALSE\033[0m" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << "\033[0;32m OK\033[0m" << std::endl;
	}

	span.addNumber(v.begin(), v.end());
	if (span.at(0) == 1 || span.at(1) == -2 || span.at(2) == 3)
		std::cout << "\033[0;32m OK\033[0m" << std::endl;
	else std::cout << "\033[1;31m FALSE\033[0m" << std::endl;

	try {
		span.addNumber(4);
		std::cout << "\033[1;31m FALSE\033[0m" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << "\033[0;32m OK\033[0m" << std::endl;
	}

	std::cout << std::endl;
}

void	shortestSpan()
{
	std::cout << "\033[0;33m///SHORTEST-SPAN///\033[0m" << std::endl;
	
	Span	s;
	s = getRandSpan(10, 100);
	printSpan(s, s.getN());
	std::cout << s.shortestSpan() << std::endl;

	Span	s_large;
	s_large = getRandSpan(100000, 10000000);
	std::cout << s_large.shortestSpan() << std::endl;


	Span	one(1);
	one.addNumber(4);
	try {
		one.shortestSpan();
		std::cout << "\033[1;31m FALSE\033[0m" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << "\033[0;32m OK\033[0m" << std::endl;
	}

	std::cout << std::endl;
}

void	longestSpan()
{
	std::cout << "\033[0;33m///LONGEST-SPAN///\033[0m" << std::endl;
	
	Span	s;
	s = getRandSpan(10, 100);
	printSpan(s, s.getN());
	std::cout << s.longestSpan() << std::endl;

	Span	s_large;
	s_large = getRandSpan(100000, 10000000);
	std::cout << s_large.longestSpan() << std::endl;


	Span	one(1);
	one.addNumber(4);
	try {
		one.longestSpan();
		std::cout << "\033[1;31m FALSE\033[0m" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << "\033[0;32m OK\033[0m" << std::endl;
	}

	std::cout << std::endl;
}

int	main()
{
	copyConstructor();
	copyOperatorOverloader();
	emptySpan();
	addOneNumber();
	addMultipleNumber();
	shortestSpan();
	longestSpan();
}

