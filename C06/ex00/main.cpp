/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:13:06 by melisportak       #+#    #+#             */
/*   Updated: 2025/07/19 12:13:08 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
        std::cout << "Examples:" << std::endl;
        std::cout << "  " << argv[0] << " 0" << std::endl;
        std::cout << "  " << argv[0] << " nan" << std::endl;
        std::cout << "  " << argv[0] << " 42.0f" << std::endl;
        std::cout << "  " << argv[0] << " 'a'" << std::endl;
        return 1;
    }
    
    ScalarConverter::convert(argv[1]);
    return 0;
} 