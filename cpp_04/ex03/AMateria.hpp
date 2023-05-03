#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>

class ICharacter;

class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria &rhs);
        AMateria& operator=(const AMateria &rhs);
        virtual ~AMateria();

        // Getters and setters
        virtual std::string const & getType() const;

        // Methods
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif