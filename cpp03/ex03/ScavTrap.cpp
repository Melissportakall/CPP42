
#include "ScavTrap.hpp"

// Kurucu: Başlangıç değerleri atanıyor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " to create." << std::endl;
}

// Yok edici: Sınıf yok edildiğinde bir mesaj yazdırılır
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " is destroy." << std::endl;
}

// guardGate fonksiyonu: Kapı bekçisi moduna geçer
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << "  Gate keeper mode." << std::endl;
}
