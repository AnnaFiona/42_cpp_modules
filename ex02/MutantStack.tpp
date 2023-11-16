#include "MutantStack.hpp"

//con- and destructors
template <typename T>
MutantStack<T>::MutantStack()
{}
template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> &M)
{
	*this = M;
}
/* template <typename T>
MutantStack<T>	&MutantStack<T>::operator = (MutantStack<T> &M)
{
	MutantStack	s;

	for (size_t i = 0; i < M.size(); i++)
		s.push(M.)
} */
template <typename T>
MutantStack<T>::~MutantStack()
{}
