#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

//methods
Base * Base::generate(void)
{
	Base	*ptr;
 	struct	timeval time;
	int		num = gettimeofday(&time, NULL);

	if (num == 0)
		num = time.tv_usec % 3;
	switch (num) {
		case 0:
			ptr = new A;
			break;
		case 1:
			ptr = new B;
			break;
		case 2:
			ptr = new C;
			break;
		default:
			ptr = new A;
			break;
	}
	return (ptr);
}
void Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}
void Base::identify(Base& p)
{
	try {
		A&	a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch (std::bad_cast) {} //not allowed
	try {
		B&	b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (std::bad_cast) {}
	try {
		C&	c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
		dynamic_cast<A&>(c);
	} catch (std::bad_cast) {}
}
