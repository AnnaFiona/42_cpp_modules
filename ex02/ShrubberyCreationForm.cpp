#include "ShrubberyCreationForm.hpp"

//con- and destructors
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = "target";
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137)
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
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

//getter
std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}