#pragma once

template<typename T>
class Array
{
private:
	T	*arr;

public:
//con- and destructors
	Array();
	Array(unsigned int n);
	Array(Array &A);
	Array	&operator = (Array &A);
	~Array();
};


#include "Array.tpp"