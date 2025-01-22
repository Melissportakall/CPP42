/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:15:54 by melisportak       #+#    #+#             */
/*   Updated: 2025/01/22 20:50:56 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int getimput(void) {
    int N;
    std::cout << "Enter the count of zombies: ";
    std::cin >> N;
    return N;
}

int main(void) {
    std::cout << "Welcome to the my Zombie Horde!" << std::endl;
    int number = getimput();
    Zombie* zombie = zombieHorde(number, "Zombie");
    for (int i = 0; i < number; i++) {
        zombie[i].announce();
    }
    delete[] zombie;
    return 0;
}