#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <vector>

template <typename T, typename container = std::deque<T> > 
class MutantStack : public std::stack<T, container>
{
public:
//con- and destructors
	MutantStack();
	MutantStack(const MutantStack<T, container> &M);
	MutantStack<T, container>	&operator = (const MutantStack<T, container> &M);
	~MutantStack();

//methods
	typedef typename	container::const_iterator	const_iterator;
	const_iterator	begin() const;
	const_iterator	end() const;
	typedef typename	container::iterator	iterator;
	iterator	begin();
	iterator	end();
};

#include "MutantStack.tpp"



template <typename T>
void	compare_equal(const T a, const T b)
{	
	std::string	red_bold("\033[1;31m");
	std::string	yellow("\033[0;33m");
	std::string white("\033[0m");
	std::string green("\033[0;32m");


	if (a == b)
		std::cout << green << "OK" << white << std::endl;
	else {
		std::cout << red_bold << "FALSE" << white << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
	}
}
template <typename T>
void	compare_not_equal(const T a, const T b)
{	
	std::string	red_bold("\033[1;31m");
	std::string	yellow("\033[0;33m");
	std::string white("\033[0m");
	std::string green("\033[0;32m");


	if (a != b)
		std::cout << green << "OK" << white << std::endl;
	else {
		std::cout << red_bold << "FALSE" << white << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
	}
}
