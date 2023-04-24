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
    this->type = "ClapTrap";
    this->init();
    std::cout << GRAY_S;
    std::cout << "ClapTrap " << this->name << " is born. " << std::endl;
    std::cout << DEFAULT;
    std::cout << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->init();
    std::cout << GRAY_S;
    std::cout << "ClapTrap " << this->name << " is born. " << std::endl;
    std::cout << DEFAULT;
    std::cout << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
    this->name = clapTrap.name;
    this->init();
    std::cout << GRAY_S;
    std::cout << "ClapTrap " << this->name << " is born. " << std::endl;
    std::cout << DEFAULT;
    std::cout << std::endl;
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
    std::cout << GRAY_S;
    std::cout << "ClapTrap " << this->name << "'s dead body has been swept. " << std::endl;
    std::cout << DEFAULT;
    std::cout << std::endl;
}

/* Actions  */

void ClapTrap::attack(const std::string& target)
{
    if(canDoAction(" attack"))
    {
        this->energy_points--;
        std::cout << this->type << " " << this->name << DEFAULT << " attacks " << target << ", causing ";
        std::cout << YELLOW << this->attack_damage;
        std::cout << " points of damage!" << std::endl;
        std::cout << DEFAULT;
        std::cout << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
        this->hit_points -= amount;
        std::cout << "ClapTrap " << this->name << " took ";
        std::cout << RED;
        std::cout << amount << " points of damage!" << std::endl;
        std::cout << DEFAULT;
        std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(canDoAction(" be repaired"))
    {
        this->energy_points--;
        this->hit_points += amount;
        std::cout << "ClapTrap " << this->name << " repairs itself, and gains ";
        std::cout << GREEN;
        std::cout << amount << " hit points!" << std::endl;
        std::cout << DEFAULT;
        std::cout << std::endl;
    }
}

/* Logic  */

int   ClapTrap::canDoAction(std::string action_name)
{
    // std::cout << this->hit_points << " " << this->energy_points << std::endl;
    if(this->hit_points <= 0)
    {
        isDeadMSG(action_name);
        return 0;
    }
    if(this->energy_points <= 0)
    {
        notEnoughEnergyMSG(action_name);
        return 0;
    }
    return 1;
}

/* Getters and Setters  */

void ClapTrap::setHitPoints(int hit_points)
{
    this->hit_points = hit_points;
}

void ClapTrap::setEnergyPoints(int energy_points)
{
    this->energy_points = energy_points;
}

void ClapTrap::setAttackDamage(int attack_damage)
{
    this->attack_damage = attack_damage;
}

/* Display */
void ClapTrap::notEnoughEnergyMSG(std::string action_name)
{
    std::cout << " * ClapTrap " << " has not enough energy for " << action_name << " *"<< std::endl;  
    std::cout << std::endl;     
}

void ClapTrap::isDeadMSG(std::string action_name)
{
    std::cout << " * ClapTrap " << " is dead, and cannot " << action_name << " *" << std::endl;  
    std::cout << std::endl;    
}

void ClapTrap::displayInfos()
{
    std::string resized_name = this->name;
    resized_name.resize(10, ' ');
    std::cout << "╔══════════╗" << std::endl;
    std::cout << "║" <<  resized_name << "║ HP : " << this->hit_points << " Energy : "  << this->energy_points << " Damage : " << this->attack_damage << "" << std::endl;
    std::cout << "╚══════════╝" << std::endl << std::endl;
}