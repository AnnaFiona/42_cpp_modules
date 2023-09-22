#include "Bureaucrat.hpp"
#include "Form.hpp"

//private member-functions
void	Bureaucrat::_checkGrade() const
{
	if (this->_grade < 1)
	{
		throw (Bureaucrat::GradeTooHighException());
	}
	if (this->_grade > 150)
	{
		throw (Bureaucrat::GradeTooLowException());
	}
}


//con- and destructor
Bureaucrat::Bureaucrat() : _name("Bureaucrat")
{
	this->_grade = 150;
}
Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name)
{
	this->_grade = grade;
	this->_checkGrade();
}
Bureaucrat::Bureaucrat(const Bureaucrat& B)
{
	*(this) = B;
	this->_checkGrade();
}
Bureaucrat& Bureaucrat::operator = (const Bureaucrat& B)
{
	this->_grade = B.getGrade();
	this->_checkGrade();
	return (*this);
}
Bureaucrat::~Bureaucrat(){}

//getter
std::string	Bureaucrat::getName() const
{
	return (this->_name);
}
int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

//member-functions
void	Bureaucrat::incrementGrade()
{
	this->_grade--;
	this->_checkGrade();
}
void	Bureaucrat::decrementGrade()
{
	this->_grade++;
	this->_checkGrade();
}
void	Bureaucrat::signForm(Form &F)
{
	try {
		F.beSigned(*this);
	} catch (std::exception& e) {
		std::cout << this->getName() << " couldn’t sign " << F.getName() << " because ";
		std::cout << e.what();
		return ;
	}
	std::cout << this->getName() << " signed " << F.getName() << std::endl;
}

//classes
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high\n");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}



//<<-operator overload function//////////////////////////////////
std::ostream& operator << (std::ostream &out, const Bureaucrat &B)
{
	out << B.getName();
	out << ", bureaucrat grade: ";
	out << B.getGrade();
	return (out);
}