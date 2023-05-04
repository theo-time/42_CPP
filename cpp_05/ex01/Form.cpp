#include "Form.hpp"

Form::Form(): 
    _name("default"), 
    _signed(false), 
    _gradeSign(150), 
    _gradeExec(150)
{
}

Form::Form(std::string const name, int gradeSign, int gradeExec): 
    _name(name), 
    _signed(false), 
    _gradeSign(gradeSign), 
    _gradeExec(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw Form::GradeTooHighException();
    else if (gradeSign > 150 || gradeExec > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form &rhs): 
    _name(rhs.getName()), 
    _signed(rhs.getSigned()), 
    _gradeSign(rhs.getGradeSign()), 
    _gradeExec(rhs.getGradeExec())
{
}

Form& Form::operator=(const Form &rhs)
{
    _signed = rhs.getSigned();
    return *this;
}

Form::~Form()
{
}

// Getters and setters
std::string const & Form::getName() const {return _name;}
bool Form::getSigned() const {return _signed;}
int Form::getGradeSign() const {return _gradeSign;}
int Form::getGradeExec() const {return _gradeExec;}

void Form::setSigned(bool signedStatus) {_signed = signedStatus;}

// Methods
void Form::beSigned(class Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeSign)
        throw Form::GradeTooLowException();
    else
        _signed = true;
}


