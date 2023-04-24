#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {

  private:
    std::string  _type;
    Brain*      _brain;

  public:
    Dog();
    Dog(const Dog &Dog);
    Dog& operator=(const Dog &Dog);
    virtual ~Dog();

    /* Actions  */
    void makeSound();

    /* Getters and setters */
    Brain* getBrain() const;

};

#endif