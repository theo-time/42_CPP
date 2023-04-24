#include "Cat.hpp"

// Coplian functions

Cat::Cat()
{
    _type = "unspecified";
    std::cout << GRAY_S "Cat default constructor called." DEFAULT << std::endl;
}

Cat::Cat(const Cat &rhs): Animal()
{
    _type = rhs.getType();
    std::cout << GRAY_S "Cat copy constructor called." DEFAULT << std::endl;
}

Cat& Cat::operator=(const Cat &rhs)
{
    _type = rhs.getType();
    return *this;
}

Cat::~Cat()
{
    std::cout << GRAY_S "Cat destructor called." DEFAULT << std::endl;
}

// Member functions 
void Cat::makeSound()
{
    std::cout << std::endl << "🐈 < * Meoww *" << std::endl << std::endl;
}