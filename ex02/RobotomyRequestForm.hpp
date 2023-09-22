#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>

class RobotomyRequestForm : public AForm
{
private:
	std::string	_target;

public:
//con- and destructors
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& R);
	RobotomyRequestForm& operator = (const RobotomyRequestForm& R);
	~RobotomyRequestForm();

//getter
	std::string	getTarget() const;
};