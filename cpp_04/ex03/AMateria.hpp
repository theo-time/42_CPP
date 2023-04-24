#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>

class ICharacter;

class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria(std::string const & type);

        // Getters and setters
        std::string const & getType() const;

        // Methods
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif