#include "Cure.hpp"      
#include "ICharacter.hpp"      

// Coplien methods

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const & Cure): AMateria(Cure) {}

Cure& Cure::operator=(const Cure &Cure) 
{
    AMateria::operator=(Cure);
    return (*this);
}

Cure::~Cure() {}


// Methods  

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}