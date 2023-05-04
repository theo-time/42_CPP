#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
{
    srand (static_cast <unsigned> (time(0)));
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target): 
    Form("RobotomyRequestForm", 72, 45), 
    _target(target)
{
    srand (static_cast <unsigned> (time(0)));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &rhs): 
    Form(rhs.getName(), rhs.getGradeSign(), rhs.getGradeExec()), 
    _target(rhs.getTarget())
{
    srand (static_cast <unsigned> (time(0)));
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    Form::operator=(rhs);
    _target = rhs.getTarget();
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    
}

// Getters and setters
std::string const & RobotomyRequestForm::getTarget() const {return _target;};
void RobotomyRequestForm::setTarget(std::string const target) {_target = target;};


// Methods
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if(!this->getSigned())
        throw Form::FormNotSignedException();
    if(executor.getGrade() > this->getGradeExec())
        throw Form::GradeTooLowException();

    float success = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    std::cout << "🪚 tchick tchack tchick tchack" << std::endl;
    std::cout << "🔩 Wizzzzzzzzzzzzzzzzz" << std::endl;
    std::cout << "🔨 Clang Clang" << std::endl;

    if(success < 0.5)
        std::cout << "* " << _target << " has been robotomized successfully. *" << std::endl;
    else
        std::cout << "* The robotomy has failed. " << _target << " died in terrible pain *" << std::endl;
}