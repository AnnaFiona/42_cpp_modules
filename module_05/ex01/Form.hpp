#pragma once

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	const int			_required_grade_execute;
	const int			_required_grade_sign;
	bool				_signed;

public:
//con- and destructor
	Form();
	Form(const std::string name, const int required_grade_execute, \
			const int required_grade_sign);
	Form(const Form& F);
	Form& operator = (const Form& F);
	~Form();

//getters
	std::string	getName() const;
	int			getRequiredGradeExecute() const;
	int			getRequiredGradeSign() const;
	bool		getSigned() const;

//member-functions
	void	beSigned(const Bureaucrat& B);

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
std::ostream& operator << (std::ostream &out, const Form &F);