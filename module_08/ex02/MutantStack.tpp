#include "MutantStack.hpp"

//con- and destructors
template <typename T, typename container>
MutantStack<T, container>::MutantStack()
{}
template <typename T, typename container>
MutantStack<T, container>::MutantStack(const MutantStack<T, container> &M) : std::stack<T, container>(M)
{}
template <typename T, typename container>
MutantStack<T, container>	&MutantStack<T, container>::operator = (const MutantStack<T, container> &M)
{
	this->c = M.c;
	return (*this);
}
template <typename T, typename container>
MutantStack<T, container>::~MutantStack()
{}

//methods
template <typename T, typename container>
typename MutantStack<T, container>::const_iterator	MutantStack<T, container>::begin() const
{
	return (this->c.begin());
}
template <typename T, typename container>
typename MutantStack<T, container>::const_iterator	MutantStack<T, container>::end() const
{
	return (this->c.end());
}

template <typename T, typename container>
typename MutantStack<T, container>::iterator	MutantStack<T, container>::begin()
{
	return (this->c.begin());
}
template <typename T, typename container>
typename MutantStack<T, container>::iterator	MutantStack<T, container>::end()
{
	return (this->c.end());
}
