/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:18:57 by melisportak       #+#    #+#             */
/*   Updated: 2025/01/22 20:59:58 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): name(name), weapon(weapon){
    return;
}

HumanA::~HumanA(void){
    return;
}

void HumanA::attack(void){
    std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
    return;
}