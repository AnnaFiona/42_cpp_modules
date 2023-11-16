#include "MutantStack.hpp"
#include <iostream>


void	copyConstructor()
{
	std::cout << "\033[0;33m///COPY-CONSTRUCTOR///\033[0m" << std::endl;
	MutantStack<int>	m;

	m.push(1);
	m.push(2);

	MutantStack<int>	copy(m);
	compare_equal<int>(m.top(), copy.top());
	copy.push(3);
	compare_not_equal<int>(m.top(), copy.top());
}

void	assignmentOperator()
{
	std::cout << "\033[0;33m///ASSIGNMENT-OPERATOR///\033[0m" << std::endl;
	MutantStack<int>	m;
	MutantStack<int>	copy;

	m.push(1);
	m.push(2);

	copy = m;

	compare_equal<int>(m.top(), copy.top());
	copy.push(3);
	m.pop();
	compare_not_equal<int>(m.top(), copy.top());
}

int	main()
{
	copyConstructor();
	assignmentOperator();

}