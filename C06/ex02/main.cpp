/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:14:31 by melisportak       #+#    #+#             */
/*   Updated: 2025/07/19 12:14:32 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include <iostream>


int main() {
    
    
    std::cout << "Testing generate() and identify() functions:" << std::endl;
    std::cout << "=============================================" << std::endl;
    
    for (int i = 0; i < 5; i++) {
        Base* ptr = generate();
        
        std::cout << "Test " << (i + 1) << ":" << std::endl;
        std::cout << "  Pointer identify: ";
        identify(ptr);
        std::cout << "  Reference identify: ";
        identify(*ptr);
        std::cout << std::endl;
        
        delete ptr;
    }
    
    return 0;
} 