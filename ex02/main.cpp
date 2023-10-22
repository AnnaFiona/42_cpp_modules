#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	Base *ptr = NULL;
	ptr = ptr->generate();
	Base&	ref = *ptr;

	ptr->identify(ptr);
	ref.identify(ref);

	delete ptr;
}