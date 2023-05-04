#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm: public Form
{
    private:
        std::string _target;

    public:
        // Coplian
        ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm &rhs);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &rhs);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm(std::string const target);

        // Getters and setters
        std::string const & getTarget() const;
        void setTarget(std::string const target);

        // Methods
        void execute(Bureaucrat const & executor) const;
};

#endif