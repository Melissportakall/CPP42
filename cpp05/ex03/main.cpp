/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:26:00 by melisportak       #+#    #+#             */
/*   Updated: 2025/05/15 12:26:01 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
	Intern  cengIntern;
	AForm*  form;

	std::cout << "Intern test" << std::endl;

	std::cout << "robotomy test" << std::endl;
	form = cengIntern.makeForm("robotomy request", "Bender");
	if (form) {
		Bureaucrat boss("Boss", 1);
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	std::cout << "fail test" << std::endl;
	form = cengIntern.makeForm("coffee making", "BreakRoom");
	if (form)
		delete form;
	
	std::cout << "shrubbery test" << std::endl;
	form = cengIntern.makeForm("shrubbery creation", "Garden");
	if(form) {
		Bureaucrat boss("Boss", 1);
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}
	std::cout << "presidential test" << std::endl;
	form = cengIntern.makeForm("presidential pardon", "Bender");
	if(form) {
		Bureaucrat boss("Boss", 1);
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}
	std::cout << "Bureaucrat test random bureaucrat" << std::endl;
	Bureaucrat randomBureaucrat("Random Bureaucrat", 50);
	
	return 0;
}
