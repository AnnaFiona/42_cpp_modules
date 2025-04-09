#pragma once

#include <sys/time.h>
#include <iostream>

class Base
{
public:
	virtual ~Base();

//methods
	Base * generate(void);
	void identify(Base* p);
	void identify(Base& p);
};