#include "MateriaSource.hpp"

// Coplian methods

MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & rhs)
{
    for(int i = 0; i < 4; i++)
        _inventory[i] = rhs._inventory[i]->clone();
}

MateriaSource& MateriaSource::operator=(const MateriaSource &rhs)
{
    for(int i = 0; i < 4; i++)
        _inventory[i] = rhs._inventory[i]->clone();
    return *this;
}

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++)
        delete _inventory[i];
}

// Methods

void MateriaSource::learnMateria(AMateria* m)
{
    for(int i = 0; i < 4; i++)
    {
        if(_inventory[i] == NULL)
        {
            _inventory[i] = m->clone();
            break;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for(int i = 0; i < 4; i++)
    {
        if(_inventory[i]->getType() == type)
        {
            return(_inventory[i]->clone());
            break;
        }
    }
    return (NULL);
}