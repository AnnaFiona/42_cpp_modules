#pragma once
#include <iostream>
#include <stdexcept>

template<typename T, typename F>
void	iter(T *arr, const size_t len, F func) throw(std::invalid_argument)
{
	if (arr == NULL)
		throw std::invalid_argument("arr == NULL");
	for (size_t x = 0; x < len; x++)
		func(arr[x]);
}


template<typename T>
void	add(T& x)
{
	x++;
}
