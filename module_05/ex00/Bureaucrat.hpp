#pragma once
  
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

public:
//con- and destructor
	Bureaucrat();
	Bureaucrat(const std::string name, const int grade);
	Bureaucrat(const Bureaucrat& B);
	Bureaucrat& operator = (const Bureaucrat& B);
	~Bureaucrat();

//getters
	std::string	getName() const;
	int			getGrade() const;

//member-functions
	void	incrementGrade();
	void	decrementGrade();

//classes
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};


//<<-operator overload function//////////////////////////////////
std::ostream& operator << (std::ostream &out, const Bureaucrat &B);