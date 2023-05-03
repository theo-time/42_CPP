#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat *macron = new Bureaucrat("Macron", 150);
    Bureaucrat BrunoLeMaire;
    try
    {
        std::cout << *macron << std::endl;
        macron->decrementGrade();   
        std::cout << *macron << std::endl;
        macron->incrementGrade();
        std::cout << *macron << std::endl;
        BrunoLeMaire = *macron;
        std::cout << BrunoLeMaire << std::endl;
        new Bureaucrat("Macron", -12);
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    delete macron;
    return 0;
}
