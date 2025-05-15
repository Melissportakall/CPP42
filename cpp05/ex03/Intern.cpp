/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:35:57 by melisportak       #+#    #+#             */
/*   Updated: 2025/05/15 12:49:42 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

static AForm* makeShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

static AForm* makeRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm* makePardon(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*formCreators[3])(const std::string&) = {
		makeShrubbery,
		makeRobotomy,
		makePardon
	};

	for (int i = 0; i < 3; ++i) {
		if (formName == names[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](target);
		}
	}

	std::cout << formName << ": Unknown form name" << std::endl;
	return NULL;
}
