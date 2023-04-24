#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

# define DEFAULT "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define YELLOW "\001\033[1;93m\002"
# define GREEN "\001\033[1;32m\002"
# define BOLD "\033[1;90m"
# define GRAY_S "\033\001[0;90m\002"

class ClapTrap {

  protected:
    std::string  name;
    std::string  type;
    int     hit_points;
    int     energy_points;
    int     attack_damage;

  public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &clapTrap);
    void operator=(const ClapTrap &clapTrap);
    ~ClapTrap();

    void init();

    /* Actions  */
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    /* Logic  */
    int   canDoAction(std::string action_name);

    /* Getters and Setters  */
    void setHitPoints(int setHitPoints);
    void setEnergyPoints(int energy_points);
    void setAttackDamage(int attack_damage);

    /* Display  */ 
    void notEnoughEnergyMSG(std::string action_name);
    void isDeadMSG(std::string action_name);
    void displayInfos();
};

#endif