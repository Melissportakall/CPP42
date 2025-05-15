/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:34:16 by melisportak       #+#    #+#             */
/*   Updated: 2025/05/15 12:34:17 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat a("Alice", 50);
	Bureaucrat b("Bob", 150);
	Form f1("FormA", 100, 120);
	Form f2("FormB", 140, 140);

	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;

	a.signForm(f1); // should succeed
	b.signForm(f1); // should fail
	b.signForm(f2); // should succeed

	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;

	try {
		Form bad("BadForm", 0, 200); // should throw
	}
	catch (std::exception& e) {
		std::cerr << "Exception on creating bad form: " << e.what() << std::endl;
	}

	return 0;
}
