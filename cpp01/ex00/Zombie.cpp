/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:11:33 by melisportak       #+#    #+#             */
/*   Updated: 2025/01/22 20:49:27 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}
Zombie::Zombie(std::string name)  {
     this->name = name;
    }
Zombie::~Zombie(void) {
    std::cout << this->name << " is dead." << std::endl;
}