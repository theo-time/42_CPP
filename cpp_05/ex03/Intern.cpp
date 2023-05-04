#include "Intern.hpp"

Intern::Intern()
{
    _forms[0] = "robotomy request";
    _forms[1] = "presidential pardon";
    _forms[2] = "shrubbery creation";
}

Intern::Intern(Intern &rhs)
{
    *this = rhs;
}

Intern& Intern::operator=(const Intern &rhs)
{
    _forms[0] = rhs._forms[0];
    _forms[1] = rhs._forms[1];
    _forms[2] = rhs._forms[2];
    return *this;
}

Intern::~Intern()
{

}

// Getters and setters


// Methods

Form *Intern::makeShrubberyCreationForm(std::string const target) const
{
    return (new ShrubberyCreationForm(target));
}

Form *Intern::makeRobotomyRequestForm(std::string const target) const
{
    return (new RobotomyRequestForm(target));
}

Form *Intern::makePresidentialPardonForm(std::string const target) const
{
    return (new PresidentialPardonForm(target));
}

Form *Intern::makeForm(std::string const formName, std::string const target) const
{
    Form *(Intern::*forms_creators[3])(std::string const target) const = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};

    for (int i = 0; i < 3; i++)
    {
        if (_forms[i].compare(formName) == 0)
        {
            return ((this->*forms_creators[i])(target));
        }
    }
    std::cout << "Form not found" << std::endl;
    return NULL;
}