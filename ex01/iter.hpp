#pragma once
#include <iostream>

template<typename T, typename F>
void	iter(T *arr, const size_t len, F func)
{
	for (size_t x = 0; x < len; x++)
		func(arr[x]);
}