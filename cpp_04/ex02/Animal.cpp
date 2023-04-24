#include "Animal.hpp"

// Coplian functions

AAnimal::AAnimal()
{
    _type = "unspecified";
    std::cout << GRAY_S "AAnimal default constructor called." DEFAULT << std::endl;
}

AAnimal::AAnimal(const AAnimal &rhs)
{
    _type = rhs.getType();
    std::cout << GRAY_S "AAnimal copy constructor called." DEFAULT << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &rhs)
{
    _type = rhs.getType();
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << GRAY_S "AAnimal destructor called." DEFAULT << std::endl;
}

// Getters and Setters

std::string AAnimal::getType() const {return _type;}


// Member functions 
void AAnimal::makeSound()
{
    std::cout << std::endl << "🦠 < * rrgfRsX%*£ffXsqzzz *" << std::endl << std::endl;
}