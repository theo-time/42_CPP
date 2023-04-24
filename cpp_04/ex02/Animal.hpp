#ifndef AANIMAL_HPP
#define AANIMAL_HPP
#include <iostream>
#include "Brain.hpp"

# define DEFAULT "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define YELLOW "\001\033[1;93m\002"
# define GREEN "\001\033[1;32m\002"
# define BOLD "\033[1;90m"
# define GRAY_S "\033\001[0;90m\002"

class AAnimal {

  private:
    std::string  _type;

  public:
    AAnimal();
    AAnimal(const AAnimal &Animal);
    AAnimal& operator=(const AAnimal &Animal);
    virtual ~AAnimal() = 0;


    /* Actions  */
    void makeSound();

    /* Getters and setters */
    Brain* getBrain() const;
    std::string getType() const;
    
  };

#endif