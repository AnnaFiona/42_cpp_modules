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
		p = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch (std::exception) {}
	try {
		p = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (std::exception) {}
	try {
		p = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	} catch (std::exception) {}
}
