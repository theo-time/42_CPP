#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;

class Bureaucrat
{
    private:
        std::string _name;
        int _grade;

    public:
        // Coplian
        Bureaucrat();
        Bureaucrat(Bureaucrat &rhs);
        Bureaucrat& operator=(const Bureaucrat &rhs);
        ~Bureaucrat();

        Bureaucrat(std::string const name, int grade);

        // Getters and setters
        std::string const & getName() const;
        int getGrade() const;
        void setGrade(int grade);

        // Methods
        void incrementGrade();
        void decrementGrade();
        void signForm(Form &form);
        void executeForm(Form const & form);

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



std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);

#endif  