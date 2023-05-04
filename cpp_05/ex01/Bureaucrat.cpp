
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
{

}

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat &rhs)
{
    _name = rhs.getName();
    _grade = rhs.getGrade();
}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs)
{
    _name = rhs.getName();
    _grade = rhs.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat()
{

}

// Getters and setters
std::string const & Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::setGrade(int grade)
{
    _grade = grade;
}

// Methods
void Bureaucrat::incrementGrade()
{
    _grade--;
    if(_grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    _grade++;
    if(_grade > 150)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signs " << form.getName() << std::endl;
    }
    catch(Form::GradeTooLowException& e)
    {
        std::cout << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

//  Operator overloads
std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat)
{
    os << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << std::endl;
    return os;
}

// Exceptions
class GradeTooHighException: public std::exception
{
    virtual const char* what() const throw();
};

class GradeTooLowException: public std::exception
{
    virtual const char* what() const throw();
};

