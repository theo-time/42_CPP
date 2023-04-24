#ifndef Cat_HPP
#define Cat_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal {

  private:
    std::string  _type;
    Brain*      _brain;

  public:
    Cat();
    Cat(const Cat &Cat);
    Cat& operator=(const Cat &Cat);
    virtual ~Cat();

    /* Actions  */
    void makeSound();

    /* Getters and setters */
    Brain* getBrain() const;

};

#endif