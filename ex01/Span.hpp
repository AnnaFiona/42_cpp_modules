#pragma once

#include <stdexcept>
#include <algorithm>

class Span
{
private:
	int				*_arr;
	unsigned int	_len;
	unsigned int	N;

public:
//con- and destructors
	Span();
	Span(const unsigned int n);
	Span(const Span& S);
	Span&	operator = (const Span& S);
	~Span();

//methods
	void	addNumber(int x) throw (std::out_of_range());
	int		shortestSpan() const throw (std::???());
	int		longestSpan() const throw (std::???());
};