#pragma once

#include <stdexcept>
#include <algorithm>
#include <iterator>

class Span
{
private:
	std::vector<int>	V;
	unsigned int		N;

public:
//con- and destructors
	Span();
	Span(const unsigned int n);
	Span(const Span& S);
	Span&	operator = (const Span& S);
	~Span();

//getter
	int		at(const int x) const;
	int		getN() const;

//methods
	void	addNumber(const int x);
	void	addNumber(const std::vector<int>::iterator begin, const std::vector<int>::iterator end);
	int		shortestSpan() const;
	int		longestSpan() const;
};