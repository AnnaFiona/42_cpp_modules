#pragma once

#include "Array.hpp"

//con- and destructors
template<typename T>
Array<T>::Array() : _size(0) {
	this->_arr = new T[0];
}
template<typename T>
Array<T>::Array(unsigned int n) : _size(n) {
	this->_arr = new T[n];
}
template<typename T>
Array<T>::Array(Array &A) : _size(A.size()) {
	this->_arr = new T[A.size()];
	for (unsigned int x = 0; x < this->_size; x++)
		this->_arr[x] = A._arr[x];
}
template<typename T>
Array<T>	&Array<T>::operator = (Array &A) {
	delete [] this->_arr;
	this->_arr = new T[A.size()];
	this->_size = A.size();
	for (unsigned int x = 0; x < this->_size; x++)
		this->_arr[x] = A._arr[x];
	return (*this);
}
template<typename T>
Array<T>::~Array() {
	delete [] this->_arr;
}

//methods
template<typename T>
unsigned int	Array<T>::size() const {
	return (this->_size);
}
template<typename T>
T&	Array<T>::operator [] (unsigned int x) {
	if (x >= this->_size)
		throw std::out_of_range("Error: index out of range");
	return (this->_arr[x]);
}
template<typename T>
T	Array<T>::operator [] (const unsigned int x) const {
	if (x >= this->_size)
		throw std::out_of_range("Error: index out of range");
	return (this->_arr[x]);
}