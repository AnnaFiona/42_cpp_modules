#include "ShrubberyCreationForm.hpp"
#include "fstream"

//private member-function
//I stole this tree from b'ger (https://ascii.co.uk/art/tree)
void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	std::ofstream	file;
	std::string		file_name;

	if (this->getSigned() == false)
		throw (AForm::FormNotSigned());
	if (executor.getGrade() > this->getRequiredGradeExecute())
		throw (AForm::GradeTooLowException());

	file_name = this->getTarget() + "_shrubbery";
	file.open(file_name.c_str());
	if (!file.is_open())
		throw (ShrubberyCouldNotBeCreated());

	file << "	         %%%,%%%%%%%\n";
    file << "	       ,'%% \\\\-*%%%%%%%\n";
    file << "	 ;%%%%%*%   _%%%%\"\n";
    file << "	  ,%%%       \\(_.*%%%%.\n";
    file << "	  % *%%, ,%%%%*(    '\n";
    file << "	%^     ,*%%% )\\|,%%*%,_\n";
    file << "	     *%    \\/ #).-\"*%%*\n";
    file << "	         _.) ,/ *%,\n";
    file << "	 _________/)#(____________\n";

	file.close();
}


//con- and destructors
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 137, 145)
{
	this->_target = "target";
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 137, 145)
{
	this->_target = target;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& S) : AForm(S)
{
	*(this) = S;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& S)
{
	AForm::operator=(S);
	this->_target = S._target;
	return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

//getter
std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

//classes
const char *ShrubberyCreationForm::ShrubberyCouldNotBeCreated::what() const throw()
{
	return ("Shrubbery could not be created\n");
}