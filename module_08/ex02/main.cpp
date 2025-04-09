#include "MutantStack.hpp"
#include <iostream>
#include <vector>


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

	std::cout << std::endl;
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

	std::cout << std::endl;
}

/* void	print_stack(const MutantStack<char>	m)
{
	for (typename MutantStack<char>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
} */
void	print_stack_const(const MutantStack<char>	m)
{
	for (MutantStack<char>::const_iterator it = m.begin(); it != m.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
}
void	print_stack_reverse(MutantStack<char>	m)
{
	for (MutantStack<char>::const_iterator it = m.end() - 1; it >= m.begin(); --it)
		std::cout << *it << ", ";
	std::cout << std::endl;
}

void	iterators()
{
	std::cout << "\033[0;33m///ITERATORS///\033[0m" << std::endl;
	MutantStack<char>	m;
	MutantStack<char>::iterator	it = m.begin();

	for (size_t i = 0; i < 10; i++)
		m.push(static_cast<char>(97 + i));

	for (size_t i = 0; i < 5; i++)
		it++;
	compare_equal(*it, 'f');
	
	print_stack_const(m);
	print_stack_reverse(m);

	*it = 'q';
	compare_not_equal(*it, 'f');

	/* MutantStack<char>::const_iterator cit = m.begin();
	cit = 4; */

	std::cout << std::endl;
}

void	vector_stack()
{
	std::cout << "\033[0;33m///VECTOR-STACK///\033[0m" << std::endl;
	MutantStack<int, std::vector<int> >	m;

	for (size_t i = 0; i < 10; i++)
		m.push(i);
	for (MutantStack<int, std::vector<int> >::iterator it = m.begin(); it != m.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
	for (MutantStack<int, std::vector<int> >::const_iterator it = m.begin(); it != m.end(); it++)
		std::cout << *it << ", ";

	std::cout << std::endl;
}

int	main()
{
	copyConstructor();
	assignmentOperator();
	iterators();
	vector_stack();
}