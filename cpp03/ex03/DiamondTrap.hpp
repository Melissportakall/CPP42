
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap{
    private:
        std::string name;
    public:
        DiamondTrap(std::string name);
        ~DiamondTrap();
        void whoAmI(void);
};