/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:24:56 by melisportak       #+#    #+#             */
/*   Updated: 2025/01/21 14:25:05 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av){
    Harl    harl;

    if(ac != 2){
        std::cout << "please provide a level of complaint" << std::endl;
        return 1;
    }
    harl.complain(av[1]);
    return 0;
}