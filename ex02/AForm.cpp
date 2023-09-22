#include "Bureaucrat.hpp"
#include "AForm.hpp"

//private member-functions
void	AForm::_checkGrade() const
{
	if (this->_required_grade_execute < 1 || this->_required_grade_sign < 1)
	{
		throw (AForm::GradeTooHighException());
	}
	if (this->_required_grade_execute > 150 || this->_required_grade_sign > 150)
	{
		throw (AForm::GradeTooLowException());
	}
}


//con- and destructor
AForm::AForm() : _name("AForm"), _required_grade_execute(42), _required_grade_sign(42)
{
	this->_signed = false;
}
AForm::AForm(const std::string name, const int required_grade_execute, const int required_grade_sign) : \
		_name(name), _required_grade_execute(required_grade_execute), _required_grade_sign(required_grade_sign)
{
	this->_signed = false;
	this->_checkGrade();
}
AForm::AForm(const AForm& F) : _name(F._name), _required_grade_execute(F._required_grade_execute), \
						_required_grade_sign(F._required_grade_sign)
{
	*(this) = F;
	this->_checkGrade();
}
AForm& AForm::operator = (const AForm& F)
{
	this->_signed = F.getSigned();
	this->_checkGrade();
	return (*this);
}
AForm::~AForm(){}

//getters
std::string	AForm::getName() const
{
	return (this->_name);
}
int			AForm::getRequiredGradeExecute() const
{
	return (this->_required_grade_execute);
}
int			AForm::getRequiredGradeSign() const
{
	return (this->_required_grade_sign);
}
bool		AForm::getSigned() const
{
	return (this->_signed);
}

//member-functions
void	AForm::beSigned(const Bureaucrat& B)
{
	if (B.getGrade() <= this->getRequiredGradeSign())
		this->_signed = true;
	else
		throw (AForm::GradeTooLowException());
}

//classes
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high\n");
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}



//<<-operator overload function//////////////////////////////////
std::ostream& operator << (std::ostream &out, const AForm &F)
{
	out << F.getName();
	out << ", aform signed: " << F.getSigned();
	out << ", required grade to sign: " << F.getRequiredGradeSign();
	out << ", required grade to execute: " << F.getRequiredGradeExecute();
	return (out);
}