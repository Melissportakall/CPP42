/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:15:00 by melisportak       #+#    #+#             */
/*   Updated: 2025/01/21 21:29:08 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void) {std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;}
void Zombie::setName(std::string name) {this->name = name;}
Zombie::~Zombie(void) {std::cout << this->name << " is dead." << std::endl;}