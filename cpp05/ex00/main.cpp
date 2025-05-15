/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:29:43 by melisportak       #+#    #+#             */
/*   Updated: 2025/05/15 12:29:44 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat a("Alice", 2);
		std::cout << a << std::endl;
		a.incrementGrade(); 
		std::cout << a << std::endl;
		a.incrementGrade(); 
	}
	catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "------------------------" << std::endl;

	try {
		Bureaucrat b("Bob", 149);
		std::cout << b << std::endl;
		b.decrementGrade(); 
		std::cout << b << std::endl;
		b.decrementGrade(); 
	}
	catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "------------------------" << std::endl;

	try {
		Bureaucrat c("Charlie", 0); 
	}
	catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat d("Dave", 200); 
	}
	catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
