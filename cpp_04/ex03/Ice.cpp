#include "Ice.hpp"
#include "ICharacter.hpp"
// Coplien methods

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const & rhs): AMateria(rhs.getType())
{
    return;
}

Ice& Ice::operator=(const Ice &Ice) 
{
    AMateria::operator=(Ice);
    return (*this);
}

// Methods  

Ice::~Ice() {}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}