
#include "DiamondTrap.hpp"

int main() {
    DiamondTrap diamondTrap("DiamondTrap");

    diamondTrap.attack("enemy");
    diamondTrap.takeDamage(10);
    diamondTrap.beRepaired(5);
    diamondTrap.whoAmI();
    diamondTrap.guardGate();
    diamondTrap.highFivesGuys();
    return 0;
}