#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
{
    
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target): 
    Form("ShrubberyCreationForm", 145, 137), 
    _target(target)
{
    
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &rhs): 
    Form(rhs.getName(), rhs.getGradeSign(), rhs.getGradeExec()), 
    _target(rhs.getTarget())
{
    
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    Form::operator=(rhs);
    _target = rhs.getTarget();
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    
}

// Getters and setters
std::string const & ShrubberyCreationForm::getTarget() const {return _target;};
void ShrubberyCreationForm::setTarget(std::string const target) {_target = target;};


// Methods
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if(!this->getSigned())
        throw Form::FormNotSignedException();
    if(executor.getGrade() > this->getGradeExec())
        throw Form::GradeTooLowException();
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
    file << "tree";
}