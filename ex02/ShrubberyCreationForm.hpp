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

//member-function
	void	execute(Bureaucrat const & executor) const;

public:
//con- and destructors
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& S);
	ShrubberyCreationForm& operator = (const ShrubberyCreationForm& S);
	~ShrubberyCreationForm();

//getter
	std::string	getTarget() const;

//classes
	class ShrubberyCouldNotBeCreated : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};