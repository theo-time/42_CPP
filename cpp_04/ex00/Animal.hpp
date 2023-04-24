#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

# define DEFAULT "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define YELLOW "\001\033[1;93m\002"
# define GREEN "\001\033[1;32m\002"
# define BOLD "\033[1;90m"
# define GRAY_S "\033\001[0;90m\002"

class Animal {

  private:
    std::string  _type;

  public:
    Animal();
    Animal(const Animal &Animal);
    Animal& operator=(const Animal &Animal);
    ~Animal();

    std::string getType() const;

    /* Actions  */
    void makeSound();
};

#endif