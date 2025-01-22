/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:20:00 by melisportak       #+#    #+#             */
/*   Updated: 2025/01/21 14:20:36 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): type(type){
    return;
}

Weapon::~Weapon(void){
    return;
}

const std::string& Weapon::getType(void){
    return this->type;
}

void Weapon::setType(std::string type){
    this->type = type;
    return;
}