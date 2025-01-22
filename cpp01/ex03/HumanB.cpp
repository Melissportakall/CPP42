/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:21:05 by melisportak       #+#    #+#             */
/*   Updated: 2025/01/21 14:21:39 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name){
    this->name = name;
    return;
}

HumanB::~HumanB(void){
    return;
}

void HumanB::setWeapon(Weapon& weapon){
    this->weapon = &weapon;
    return;
}

void HumanB::attack(void){
    std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
    return;
}