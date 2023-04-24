#include "Dog.hpp"

// Coplian functions

Dog::Dog()
{
    std::cout << GRAY_S "Dog default constructor called." DEFAULT << std::endl;
    _type = "unspecified";
    _brain = new Brain();
}

Dog::Dog(const Dog &rhs): AAnimal()
{
    std::cout << GRAY_S "Dog copy constructor called." DEFAULT << std::endl;
    _type = rhs.getType();
    _brain = new Brain(*rhs.getBrain());
}

Dog& Dog::operator=(const Dog &rhs)
{
    _type = rhs.getType();
    delete _brain;
    _brain = new Brain(*rhs.getBrain());
    return *this;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << GRAY_S "Dog destructor called." DEFAULT << std::endl;
}

// Member functions 

void Dog::makeSound()
{
    std::cout << std::endl << "🐕 < * Wooof *" << std::endl << std::endl;
}

// Getters and Setters

Brain* Dog::getBrain() const {return _brain;}