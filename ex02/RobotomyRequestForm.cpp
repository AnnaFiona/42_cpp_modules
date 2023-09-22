#include "RobotomyRequestForm.hpp"

//con- and destructors
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = "target";
}
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& R) : AForm(R)
{
	*(this) = R;
}
RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& R)
{
	AForm::operator=(R);
	this->_target = R._target;
}
RobotomyRequestForm::~RobotomyRequestForm() {}

//getter
std::string	RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}