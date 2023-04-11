#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {
    ClapTrap keynes = ClapTrap("Keynes");

    keynes.attack("Friedman");
    keynes.takeDamage(10);
    keynes.beRepaired(10);

    return 0;
}