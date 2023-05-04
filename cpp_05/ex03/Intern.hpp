#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        std::string _forms[3];

    public:
        // Coplian
        Intern();
        Intern(Intern &rhs);
        Intern& operator=(const Intern &rhs);
        ~Intern();


        // Getters and setters
        std::string const & getTarget() const;
        void setTarget(std::string const target);

        // Methods
        Form *makeForm(std::string const formName, std::string const target) const;
        Form *makeShrubberyCreationForm(std::string const target) const;
        Form *makeRobotomyRequestForm(std::string const target) const;
        Form *makePresidentialPardonForm(std::string const target) const;
};

#endif