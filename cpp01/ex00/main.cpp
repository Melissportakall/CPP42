/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:12:16 by melisportak       #+#    #+#             */
/*   Updated: 2025/01/22 20:03:12 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    Zombie zombie = Zombie("Foo");
    zombie.announce();
    Zombie* zombie2 = newZombie("Zoo");
    zombie2->announce();
    randomChump("Too");
    delete zombie2;
    return 0;
}