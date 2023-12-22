#include "RPN.hpp"

bool	is_digit(std::string::const_iterator it, std::string::const_iterator end)
{
	if (it == end)
		return (false);
	if (*it < '0' || *it > '9')
		return (false);
	if (*(it + 1) != ' ' && it + 1 != end)
		return (false);
	return (true);
}

bool	is_operator(std::string::const_iterator it, std::string::const_iterator end)
{
	if (it == end)
		return (false);
	if (*it != '-' && *it != '+' && *it != '*' && *it != '/')
		return (false);
	if (*(it + 1) != ' ' && it + 1 != end)
		return (false);
	return (true);
}

long int get_result(const long int a, const long int b, const int operant)
{
	if (b == 0 && operant == '/')
		throw std::runtime_error("operation is invalid: can't divide through 0");
	switch (operant) {
		case '+' : 
			return (a + b);
		case '-' : 
			return (a - b);
		case '*' : 
			return (a * b);
		case '/' : 
			return (a / b);
		default:
			return (0); //should never happen
	}
}

void	do_operation(std::stack<int>& stack, const char operant)
{
	long int	result;
	int			element;

	if (stack.size() < 2)
		throw std::runtime_error("operation is invalid");
	element = stack.top();
	stack.pop();
	result = get_result(stack.top(), element, operant);
	stack.pop();
	if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
		throw std::overflow_error("result is exceeding int limits");
	stack.push(result);
}

void	RPN(const std::string operation)
{
	std::stack<int>	stack;
	std::string::const_iterator	it = operation.begin();

	while (it < operation.end())
	{
		while (*it == ' ')
			it++;
		if (is_digit(it, operation.end()))
			stack.push(*it - '0');
		else if (is_operator(it, operation.end()))
			do_operation(stack, *it);
		else if (it != operation.end())
			throw std::invalid_argument("invalid argument");
		it++;
	}
	if (stack.size() != 1)
		throw std::runtime_error("operation is invalid");
	std::cout << stack.top() << std::endl;
}