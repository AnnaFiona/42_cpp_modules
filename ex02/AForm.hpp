#pragma once

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	const int			_required_grade_execute;
	const int			_required_grade_sign;
	bool				_signed;

//pure virtual member-function
	virtual void	action() const = 0;

public:
//con- and destructor
	AForm();
	AForm(const std::string name, const int required_grade_execute, \
			const int required_grade_sign);
	AForm(const AForm& F);
	AForm& operator = (const AForm& F);
	virtual ~AForm();

//getters
	std::string	getName() const;
	int			getRequiredGradeExecute() const;
	int			getRequiredGradeSign() const;
	bool		getSigned() const;

//member-functions
	void	execute(Bureaucrat const& executor) const;
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
	class FormNotSigned : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};


//<<-operator overload function//////////////////////////////////
std::ostream& operator << (std::ostream &out, const AForm &F);