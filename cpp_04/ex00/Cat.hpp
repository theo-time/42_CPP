#ifndef Cat_HPP
#define Cat_HPP
#include "Animal.hpp"

class Cat: public Animal {

  private:
    std::string  _type;

  public:
    Cat();
    Cat(const Cat &Cat);
    Cat& operator=(const Cat &Cat);
    ~Cat();

    /* Actions  */
    virtual void makeSound();
};

#endif