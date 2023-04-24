#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main( void ) {
    Dog snoopDog = Dog();
    Animal escheriaColi = Animal();
    Cat garfield = Cat();

    escheriaColi.makeSound();
    snoopDog.makeSound();
    garfield.makeSound();

    return 0;
}