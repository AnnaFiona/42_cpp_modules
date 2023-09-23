#pragma once

#include "AForm.hpp"
#include <iostream>
#include <string>

class Intern
{
public:
//con- and destructors
	Intern();
	Intern(const Intern& I);
	Intern& operator = (const Intern& I);
	~Intern();

//member-function
	AForm*	makeForm(const std::string form_name, const std::string target);
};