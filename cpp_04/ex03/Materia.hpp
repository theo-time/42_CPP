#ifndef MATERIA_HPP
#define MATERIA_HPP
#include "ICharacter.hpp"
#include <iostream>

class Materia
{
    protected:
        std::string _type;

    public:
        Materia();
        Materia(std::string const & type);
        Materia& operator=(const Materia &materia);
        ~Materia();

        // Getters and setters
        std::string const & getType() const;


        virtual Materia* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif