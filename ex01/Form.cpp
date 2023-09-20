#include "Form.hpp"

//private member-functions


//con- and destructor
Form::Form() : _name("Form"), _required_grade_execute(), _required_grade_sign(required_grade_sign)
{
	this->_signed = false;
}
Form::Form(const std::string name, const int required_grade_execute, const int required_grade_sign) : \
		_name(name), _required_grade_execute(required_grade_execute), _required_grade_sign(required_grade_sign)
{
	this->_signed = false;
}
Form::Form(Form& F)
{
	*(this) = F;
}
Form& Form::operator = (Form& F)
{
	this->_signed = F.getSigned();
	return (*this);
}
Form::~Form(){}

//getters
std::string	Form::getName() const
{
	return (this->_name);
}
int			Form::getRequiredGradeExecute() const
{
	return (this->_required_grade_execute);
}
int			Form::getRequiredGradeSign() const
{
	return (this->_required_grade_sign);
}
bool		Form::getSigned() const
{
	return (this->_signed);
}


//classes
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high\n");
}
const char *Form::GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low\n");
}


//<<-operator overload function//////////////////////////////////
std::ostream& operator << (std::ostream &out, const Form &F)
{
	out << F.getName();
	out << ", form signed: " << F.getSigned();
	out << ", required grade to sign: " << F.getRequiredGradeSign();
	out << ", required grade to execute: " << F.getRequiredGradeExecute();
	return (out);
}