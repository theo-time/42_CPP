#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat *macron = new Bureaucrat("Macron", 1);
    Bureaucrat *BrunoLeMaire = new Bureaucrat("BrunoLeMaire", 10);
    Intern *leStagiaire = new Intern();
    Form *form = new PresidentialPardonForm("Donald Trump");
    Form *form2 = new RobotomyRequestForm("Marlene Schiappa");
    Form *form3 = leStagiaire->makeForm("shrubbery creation", "forest");
    Form *form4 = leStagiaire->makeForm("Rats denazification", "paris");
    try
    {
        BrunoLeMaire->signForm(*form);
        macron->signForm(*form2);
        macron->signForm(*form3);
        macron->signForm(*form4);
        macron->executeForm(*form);
        BrunoLeMaire->executeForm(*form2);
        BrunoLeMaire->executeForm(*form3);
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    catch (Form::GradeTooHighException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    delete macron;
    delete BrunoLeMaire;
    delete form;
    delete form2;
    delete form3;
    return 0;
}
