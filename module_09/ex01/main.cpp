#include "RPN.hpp"

int main(const int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: can only take one argument" << std::endl;
		return (0);
	}
	
	try {
		RPN(argv[1]);
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}