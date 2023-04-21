#include "ScavTrap.hpp"

void    ScavTrap::init()
{
    this->name = "Anonymous";
    this->type = "ScavTrap";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;    
}

ScavTrap::ScavTrap()
{
    init();
    std::cout << GRAY_S;
    std::cout << "ScavTrap constructor" << std::endl;
    std::cout << DEFAULT;
}

ScavTrap::ScavTrap(std::string name)
{
    init();
    this->name = name;
    std::cout << GRAY_S;
    std::cout << "ScavTrap constructor" << std::endl;
    std::cout << this->name << std::endl;
    std::cout << DEFAULT;
}

ScavTrap::~ScavTrap()
{
    std::cout << GRAY_S;
    std::cout << "ScavTrap destructor" << std::endl;
    std::cout << DEFAULT;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap "<< this->name << " entered Gate Keeper mode." << std::endl;
}