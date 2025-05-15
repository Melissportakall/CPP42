/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:34:50 by melisportak       #+#    #+#             */
/*   Updated: 2025/05/15 12:34:51 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

    Bureaucrat low("LowRank", 150);
    Bureaucrat mid("MidRank", 70);
    Bureaucrat high("HighRank", 1);

    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Rick");

	std::cout << "\n=== Form Details ===" << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;
	std::cout << shrub << std::endl;
	
	std::cout << "\n=== No signed forms not executed ===" << std::endl;
	low.executeForm(shrub);
	mid.executeForm(robot);
	high.executeForm(pardon);

    std::cout << "\n=== Signing Tests ===" << std::endl;

    low.signForm(shrub);

    mid.signForm(shrub);

    high.signForm(robot);
    high.signForm(pardon);

    std::cout << "\n=== Execution Tests ===" << std::endl;

    low.executeForm(shrub);

    high.executeForm(shrub);

    mid.executeForm(robot);

    high.executeForm(robot);
    
    high.executeForm(pardon);

    return 0;
}
