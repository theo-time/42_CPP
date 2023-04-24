#include "Cat.hpp"

// Coplian functions

Cat::Cat()
{
    std::cout << GRAY_S "Cat default constructor called." DEFAULT << std::endl;
    _type = "unspecified";
    _brain = new Brain();
}

Cat::Cat(const Cat &rhs): Animal()
{
    std::cout << GRAY_S "Cat copy constructor called." DEFAULT << std::endl;
    _type = rhs.getType();
    _brain = new Brain(*rhs.getBrain());
}

Cat& Cat::operator=(const Cat &rhs)
{
    _type = rhs.getType();
    delete _brain;
    _brain = new Brain(*rhs.getBrain());
    return *this;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << GRAY_S "Cat destructor called." DEFAULT << std::endl;
}

// Member functions 

void Cat::makeSound()
{
    std::cout << std::endl << "🐈 < * Meoww *" << std::endl << std::endl;
}

// Getters and Setters

Brain* Cat::getBrain() const {return _brain;}
