#include "Dog.hpp"

// Coplian functions

Dog::Dog()
{
    _type = "unspecified";
    std::cout << GRAY_S "Dog default constructor called." DEFAULT << std::endl;
}

Dog::Dog(const Dog &rhs): Animal()
{
    _type = rhs.getType();
    std::cout << GRAY_S "Dog copy constructor called." DEFAULT << std::endl;
}

Dog& Dog::operator=(const Dog &rhs)
{
    _type = rhs.getType();
    return *this;
}

Dog::~Dog()
{
    std::cout << GRAY_S "Dog destructor called." DEFAULT << std::endl;
}

// Member functions 
void Dog::makeSound()
{
    std::cout << std::endl << "🐕 < * Wooof *" << std::endl << std::endl;
}