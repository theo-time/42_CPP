#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
    
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target): 
    Form("PresidentialPardonForm", 25, 5), 
    _target(target)
{
    
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &rhs): 
    Form(rhs.getName(), rhs.getGradeSign(), rhs.getGradeExec()), 
    _target(rhs.getTarget())
{
    
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    Form::operator=(rhs);
    _target = rhs.getTarget();
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    
}

// Getters and setters
std::string const & PresidentialPardonForm::getTarget() const {return _target;};
void PresidentialPardonForm::setTarget(std::string const target) {_target = target;};


// Methods
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if(!this->getSigned())
        throw Form::FormNotSignedException();
    if(executor.getGrade() > this->getGradeExec())
        throw Form::GradeTooLowException();
    std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}