#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
    public:
        MateriaSource();
        MateriaSource(MateriaSource const & MateriaSource);
        MateriaSource& operator=(const MateriaSource &MateriaSource);
        ~MateriaSource();

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);  
};

#endif