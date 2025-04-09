#include "Bureaucrat.hpp"
#include "AForm.hpp"

//con- and destructor
Bureaucrat::Bureaucrat() : _name("Bureaucrat")
{
	this->_grade = 150;
}
Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& B) : _name(B.getName())
{
	*(this) = B;
}
Bureaucrat& Bureaucrat::operator = (const Bureaucrat& B)
{
	this->_grade = B.getGrade();
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
void	Bureaucrat::executeForm(AForm const& form)
{
	try {
		form.execute(*this);
	} catch (std::exception& e) {
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because ";
		std::cout << e.what();
		return ;
	}
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
}
void	Bureaucrat::signForm(AForm &F)
{
	try {
		F.beSigned(*this);
	} catch (std::exception& e) {
		std::cout << this->getName() << " couldn't sign " << F.getName() << " because ";
		std::cout << e.what();
		return ;
	}
	std::cout << this->getName() << " signed " << F.getName() << std::endl;
}
void	Bureaucrat::incrementGrade()
{
	if (this->getGrade() - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
}
void	Bureaucrat::decrementGrade()
{
	if (this->getGrade() + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
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