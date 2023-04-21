#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"


class ScavTrap: public ClapTrap {

  public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &clapTrap);
    void operator=(const ScavTrap &clapTrap);
    ~ScavTrap();

    void init();
    void guardGate();

};

#endif