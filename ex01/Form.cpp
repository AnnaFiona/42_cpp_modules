#include "Bureaucrat.hpp"
#include "Form.hpp"

//private member-functions
void	Form::_checkGrade() const
{
	if (this->_required_grade_execute < 1 || this->_required_grade_sign < 1)
	{
		throw (Form::GradeTooHighException());
	}
	if (this->_required_grade_execute > 150 || this->_required_grade_sign > 150)
	{
		throw (Form::GradeTooLowException());
	}
}


//con- and destructor
Form::Form() : _name("Form"), _required_grade_execute(42), _required_grade_sign(42)
{
	this->_signed = false;
}
Form::Form(const std::string name, const int required_grade_execute, const int required_grade_sign) : \
		_name(name), _required_grade_execute(required_grade_execute), _required_grade_sign(required_grade_sign)
{
	this->_signed = false;
	this->_checkGrade();
}
Form::Form(const Form& F) : _name(F._name), _required_grade_execute(F._required_grade_execute), \
						_required_grade_sign(F._required_grade_sign)
{
	*(this) = F;
	this->_checkGrade();
}
Form& Form::operator = (const Form& F)
{
	this->_signed = F.getSigned();
	this->_checkGrade();
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

//member-functions
void	Form::beSigned(const Bureaucrat& B)
{
	if (B.getGrade() <= this->getRequiredGradeSign())
		this->_signed = true;
	else
		throw (Form::GradeTooLowException());
}

//classes
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high\n");
}
const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}



//<<-operator overload function//////////////////////////////////
std::ostream& operator << (std::ostream &out, const Form &F)
{
	out << F.getName();
	if (F.getSigned() == true)
		out << ", is signed";
	else
		out << ", is unsigned";
	out << ", required grade to sign: " << F.getRequiredGradeSign();
	out << ", required grade to execute: " << F.getRequiredGradeExecute();
	return (out);
}