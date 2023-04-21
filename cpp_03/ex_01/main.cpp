#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
    ScavTrap keynes = ScavTrap("Keynes");

    keynes.attack("Friedman");
    keynes.displayInfos();
    keynes.takeDamage(5);
    keynes.displayInfos();
    keynes.beRepaired(10);
    keynes.displayInfos();
    keynes.guardGate();

    return 0;
}