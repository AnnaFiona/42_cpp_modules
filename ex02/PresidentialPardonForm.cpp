#include "PresidentialPardonForm.hpp"

//private member-function
void	PresidentialPardonForm::action() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


//con- and destructors
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 5, 25)
{
	this->_target = "target";
}
PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 5, 25)
{
	this->_target = target;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& P) : AForm(P)
{
	*(this) = P;
}
PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& P)
{
	AForm::operator=(P);
	this->_target = P._target;
	return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm() {}

//getter
std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}