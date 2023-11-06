#include "Span.hpp"

Span::Span() : _len(0), N(0)
{
	this->_arr = new int[0];
}
Span::Span(const unsigned int n) : _len(0), N(n)
{
	this->_arr = new int[n];
}
Span::Span(const Span &S) : _len(S._len), N(S.N)
{
	this->_arr = new int[S.N];
	for (size_t x = 0; x < this->N; x++)
		this->_arr[x] = S._arr[x];
}
Span	&Span::operator = (const Span &S)
{
	delete [] this->_arr;
	this->_arr = new int[S.N];
	this->_len = S._len;
	this->N = S.N;
	for (size_t x = 0; x < this->N; x++)
		this->_arr[x] = S._arr[x];
	return (*this);
}
Span::~Span()
{
	delete [] this->_arr;
}

//methods
void	Span::addNumber(int x) throw (std::out_of_range())
{
	if (this->_len + 1 == this->N)
		throw (std::out_of_range("cannot add number; array is full"));
	this->_len++;
	this->_arr[this->_len] = x;
}
int		Span::shortestSpan() const throw (std::???())
{
	if (this->N <= 1)
		throw (std::???("array doesn't have enough numbers"));
	
	int	*copy = new int[this->N];

	for (size_t x = 0; x < this->N; x++)
		copy[x] = this->_arr[x];
	std::sort(copy, copy + this->_len);



	delete [] copy;
}
int		Span::longestSpan() const throw (std::???())
{
	if (this->N <= 1)
		throw (std::???("array doesn't have enough numbers"));

	int	*copy = new int[this->N];
	int	span = 0;

	for (size_t x = 0; x < this->N; x++)
		copy[x] = this->_arr[x];
	std::sort(copy, copy + this->_len);
	for (int x = copy[0]; x < copy[this->_len]; x++)
		span++;
	delete [] copy;
	return (span);
}