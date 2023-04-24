#include "AMateria.hpp"

AMateria::AMateria(std::string const & type): _type(type) {
    return ;
}

// Getters and setters

std::string const & AMateria::getType() const {
    return this->_type;
}
