#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm: public Form
{
    private:
        std::string _target;

    public:
        // Coplian
        RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm &rhs);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &rhs);
        ~RobotomyRequestForm();

        RobotomyRequestForm(std::string const target);

        // Getters and setters
        std::string const & getTarget() const;
        void setTarget(std::string const target);

        // Methods
        void execute(Bureaucrat const & executor) const;
};

#endif