#include "RobotomyRequestForm.hpp"
#include <sys/time.h>

//private member-function
void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (this->getSigned() == false)
		throw (AForm::FormNotSigned());
	if (executor.getGrade() > this->getRequiredGradeExecute())
		throw (AForm::GradeTooLowException());

	struct timeval time;
    int	num = gettimeofday(&time, NULL);
	if (num == 0)
		num = time.tv_usec % 2;
	std::cout << "Bzzz clACk Clak" << std::endl;

	switch (num)
	{
		case 0:
			std::cout << this->getTarget() << " has been robotomized successfully" <<std::endl;
			break;
		case 1:
			std::cout << "The robotomy has failed" <<std::endl;
			break;
		case -1:
			std::cout << "The robotomy has failed" <<std::endl;
			break;
	}
}


//con- and destructors
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 45, 72)
{
	this->_target = "target";
}
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 45, 72)
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
	return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm() {}

//getter
std::string	RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}