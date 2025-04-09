#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>

class PresidentialPardonForm : public AForm
{
private:
	std::string	_target;

//member-function
	void	execute(Bureaucrat const & executor) const;

public:
//con- and destructors
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& P);
	PresidentialPardonForm& operator = (const PresidentialPardonForm& P);
	~PresidentialPardonForm();

//getter
	std::string	getTarget() const;

};