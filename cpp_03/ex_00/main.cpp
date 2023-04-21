#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {
    ClapTrap keynes = ClapTrap("Keynes");

    keynes.attack("Friedman");
    keynes.displayInfos();
    keynes.takeDamage(5);
    keynes.displayInfos();
    keynes.beRepaired(10);
    keynes.displayInfos();

    return 0;
}