#include "Animal.hpp"

// Coplian functions

Animal::Animal()
{
    _type = "unspecified";
    std::cout << GRAY_S "Animal default constructor called." DEFAULT << std::endl;
}

Animal::Animal(const Animal &rhs)
{
    _type = rhs.getType();
    std::cout << GRAY_S "Animal copy constructor called." DEFAULT << std::endl;
}

Animal& Animal::operator=(const Animal &rhs)
{
    _type = rhs.getType();
    return *this;
}

Animal::~Animal()
{
    std::cout << GRAY_S "Animal destructor called." DEFAULT << std::endl;
}

// Getters and Setters

std::string Animal::getType() const {return _type;}


// Member functions 
void Animal::makeSound()
{
    std::cout << std::endl << "🦠 < * rrgfRsX%*£ffXsqzzz *" << std::endl << std::endl;
}