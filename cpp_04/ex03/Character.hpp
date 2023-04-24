#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
#include "AMateria.hpp"


class Character: public ICharacter
{
    private:
        AMateria* _inventory[4];
        std::string _name;


    public:
        Character();
        Character(std::string const & name);
        Character& operator=(const Character &Character);
        ~Character();

        // Getters and setters
        std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);

};

#endif