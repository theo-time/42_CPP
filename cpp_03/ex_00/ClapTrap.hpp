#ifndef CLAPTRAP_HPP
#include <iostream>

class ClapTrap {

  private:
    std::string  name;
    int     hit_points;
    int     energy_points;
    int     attack_damage;

  public:
    ClapTrap();
    ClapTrap::ClapTrap(std::string name);
    ClapTrap(const ClapTrap &clapTrap);
    void operator=(const ClapTrap &clapTrap);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void init();
};

#endif