#pragma once

#include <stdexcept>

template<typename T>
class Array
{
private:
	T				*_arr;
	unsigned int	_size;

public:
//con- and destructors
	Array();
	Array(unsigned int n);
	Array(Array &A);
	Array	&operator = (Array &A);
	~Array();

//methods
	unsigned int	size() const;
	T&	operator [] (unsigned int x);
	T	operator [] (const unsigned int x) const;
};


#include "Array.tpp"