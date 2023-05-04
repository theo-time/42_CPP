#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    private:
        std::string const _name;
        bool _signed;
        int const _gradeSign;
        int const _gradeExec;

    public:
        // Coplian
        Form();
        Form(Form &rhs);
        Form& operator=(const Form &rhs);
        ~Form();

        Form(std::string const name, int gradeSign, int gradeExec);

        // Getters and setters
        std::string const & getName() const;
        int getGradeSign() const;
        int getGradeExec() const;
        bool getSigned() const;
        void setSigned(bool signedStatus);

        // Methods
        void beSigned(class Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const;

        // Exceptions
        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw() {return "grade is too high";};
        };
        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw()  {return "grade is too low";};
        };
};

std::ostream& operator<<(std::ostream& os, const Form& Form);

#endif
