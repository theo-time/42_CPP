#include "Character.hpp"

// Coplien methods

Character::Character(): _name("default") 
{
    for(int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(std::string const & name): _name(name) 
{
    for(int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character& Character::operator=(const Character &rhs)
{
    _name = rhs._name;
    for(int i = 0; i < 4; i++)
        _inventory[i] = rhs._inventory[i]->clone();
    return *this;
}

Character::~Character()
{
    for(int i = 0; i < 4; i++)
    {
        if(_inventory[i])
            std::cout << "deleting " << _inventory[i]->getType() <<  std::endl;
        delete _inventory[i];
    }

}

// Methods
void Character::equip(AMateria* m)
{
    for(int i = 0; i < 4; i++)
    {
        if(_inventory[i] == NULL)
        {
            _inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if(_inventory[idx])
        _inventory[idx]->use(target);
}

//  Getters and setters

std::string const & Character::getName() const
{
    return _name;
}