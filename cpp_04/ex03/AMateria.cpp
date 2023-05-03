#include "AMateria.hpp"

// Coplian methods

AMateria::AMateria()
{

}

AMateria::AMateria(const AMateria &rhs): _type(rhs.getType()) {
    return ;
}

AMateria::AMateria(std::string const & type): _type(type) {
    return ;
}

AMateria& AMateria::operator=(const AMateria &rhs)
{
    _type = rhs.getType();
    return *this;
}

AMateria::~AMateria()
{

}

// Getters and setters

std::string const & AMateria::getType() const {
    return this->_type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}