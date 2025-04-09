#pragma once

#include <iostream>
#include <string>

class Brain
{
public:
	std::string ideas[100];

//con- and destructors
	Brain();
	Brain(Brain &C);
	Brain	&operator = (Brain &C);
	virtual ~Brain();
};