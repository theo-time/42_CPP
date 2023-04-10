#include "ClapTrap.hpp"

void ClapTrap::init()
{
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap()
{
    this->name = "Bob";
    this->init();
    std::cout << "ClapTrap " << this->name << " is born. " << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->init();
    std::cout << "ClapTrap " << this->name << " is born. " << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
    this->name = clapTrap.name;
    this->init();
    std::cout << "ClapTrap " << this->name << " is born. " << std::endl;
}

void ClapTrap::operator=(const ClapTrap &clapTrap)
{
    this->name = clapTrap.name;
    this->hit_points = clapTrap.hit_points;
    this->energy_points = clapTrap.energy_points;
    this->attack_damage = clapTrap.attack_damage;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << "'s dead body has been swept. " << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
    this->energy_points--;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << "points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->name << " took " <<  amount << "points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    this->energy_points--;
    std::cout << "ClapTrap " << this->name << " repairs itself, and gains " << amount << "hit points!" << std::endl;
}