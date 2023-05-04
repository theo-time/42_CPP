#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm: public Form
{
    private:
        std::string _target;

    public:
        // Coplian
        PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm &rhs);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &rhs);
        ~PresidentialPardonForm();

        PresidentialPardonForm(std::string const target);

        // Getters and setters
        std::string const & getTarget() const;
        void setTarget(std::string const target);

        // Methods
        void execute(Bureaucrat const & executor) const;
};

#endif