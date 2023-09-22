#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>

class ShrubberyCreationForm : public AForm
{
private:
	std::string	_target;

public:
//con- and destructors
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& S);
	ShrubberyCreationForm& operator = (const ShrubberyCreationForm& S);
	~ShrubberyCreationForm();

//getter
	std::string	getTarget() const;
};