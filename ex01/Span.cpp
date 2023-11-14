#include "Span.hpp"
#include <iostream>

Span::Span() : N(0) {}
Span::Span(const unsigned int n) : N(n) {}
Span::Span(const Span &S) : V(S.V), N(S.N) {}
Span	&Span::operator = (const Span &S)
{
	this->V = S.V;
	this->N = S.N;
	return (*this);
}
Span::~Span() {}

//getter
int		Span::at(const int x) const
{
	return (this->V.at(x));
}
int		Span::getN() const
{
	return (this->N);
}


//methods
void	Span::addNumber(const int x)
{
	if (this->V.size() == this->N)
		throw (std::length_error("cannot add number: vector is full"));
	this->V.push_back(x);
}
void	Span::addNumber(const std::vector<int>::iterator begin, const std::vector<int>::iterator end)
{
	if (end - begin + this->V.size() > N)
		throw (std::length_error("cannot add number: too many numbers to add or vector is full"));
	this->V.insert(this->V.end(), begin, end);
}
int		Span::shortestSpan() const
{
	if (this->N <= 1 || this->V.size() <= 1)
		throw (std::length_error("not enough numbers"));
	
	std::vector<int>					copy(this->V);
	std::vector<int>::const_iterator	iter = copy.begin();
	int									span = 0;

	std::sort(copy.begin(), copy.end());
	span = abs(*iter - *(iter + 1));
	while (iter + 1 < copy.end()) {
		if (span > abs(*iter - *(iter + 1)))
			span = abs(*iter - *(iter + 1));
		iter++;
	}
	return (span);
}
int		Span::longestSpan() const
{
	if (this->N <= 1 || this->V.size() <= 1)
		throw (std::length_error("not enough numbers"));

	std::vector<int>	copy(this->V);

	std::sort(copy.begin(), copy.end());
	return (abs(copy.front() - copy.back()));
}