#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat *macron = new Bureaucrat("Macron", 1);
    Bureaucrat *BrunoLeMaire = new Bureaucrat("BrunoLeMaire", 10);
    Form *form = new Form("Form", 3, 10);
    try
    {
        BrunoLeMaire->signForm(*form);
        macron->signForm(*form);
        form->beSigned(*macron);
        form->beSigned(*BrunoLeMaire);
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
    return 0;
}
