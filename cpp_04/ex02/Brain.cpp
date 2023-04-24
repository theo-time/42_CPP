#include "Brain.hpp"

// Coplian functions

Brain::Brain()
{
    std::cout << GRAY_S "Brain default constructor called." DEFAULT << std::endl;
}

Brain::Brain(const Brain &rhs)
{
    for(int i = 0; i < 100; i++)
        _ideas[i] = rhs.getIdeas()[i];
    std::cout << GRAY_S "Brain copy constructor called." DEFAULT << std::endl;
}

Brain& Brain::operator=(const Brain &rhs)
{
    for(int i = 0; i < 100; i++)
        _ideas[i] = rhs.getIdeas()[i];
    return *this;
}

Brain::~Brain()
{
    std::cout << GRAY_S "Brain destructor called." DEFAULT << std::endl;
}

// Log all the ideas
void Brain::printIdeas()
{
    for(int i = 0; i < 100; i++)
        if(_ideas[i].length() > 0)
            std::cout << _ideas[i] << std::endl;
}

// Getters and Setters

std::string* Brain::getIdeas() const {return (std::string*) _ideas;}
void Brain::setIdea(int i, std::string idea) {_ideas[i] = idea;}