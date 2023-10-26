#pragma once

#include "Array.hpp"

//con- and destructors
template<typename T>
Array<T>::Array()
{}
template<typename T>
Array<T>::Array(unsigned int n)
{}
template<typename T>
Array<T>::Array(Array &A) {
	*this = A;
}
template<typename T>
Array<T>	&Array<T>::operator = (Array &A)
{}
template<typename T>
Array<T>::~Array()
{}