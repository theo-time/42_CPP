#include "ScavTrap.hpp"

void    ScavTrap::init()
{
    this->type = "ScavTrap";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;    
}

ScavTrap::ScavTrap()
{
    init();
    this-> name = "Anonymous";
    std::cout << GRAY_S;
    std::cout << "ScavTrap constructor" << std::endl << std::endl;
    std::cout << DEFAULT;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    init();
    std::cout << GRAY_S;
    std::cout << "ScavTrap constructor" << std::endl << std::endl;
    std::cout << DEFAULT;
}

ScavTrap::~ScavTrap()
{
    std::cout << GRAY_S;
    std::cout << "ScavTrap destructor" << std::endl << std::endl;
    std::cout << DEFAULT;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap "<< this->name << " entered Gate Keeper mode." << std::endl << std::endl;
}