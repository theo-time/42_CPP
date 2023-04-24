#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main( void ) {
    // Dog dog = Dog();
    // Dog dog2 = Dog();

    // dog.getBrain()->setIdea(0, "I am a dog");
    // std::cout << "dog 1 ideas :" << std::endl;
    // dog.getBrain()->printIdeas();
    // std::cout << "dog 2 ideas :" << std::endl;
    // dog2.getBrain()->printIdeas();

    AAnimal* animals[10];

    for(int i = 0; i < 5; i++)
    {
        animals[i] = new Dog();
        std::cout << std::endl;
    }
    for(int i = 5; i < 10; i++)
    {
        animals[i] = new Cat();
        std::cout << std::endl;
    }

    for(int i = 0; i < 10; i++)
    {
        delete animals[i];
        std::cout << std::endl;
    }
    return 0;
}