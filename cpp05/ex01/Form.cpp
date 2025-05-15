/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:33:43 by melisportak       #+#    #+#             */
/*   Updated: 2025/05/15 12:33:44 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Untitled"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeSign, int gradeExec)
	: name(name), isSigned(false), gradeToSign(gradeSign), gradeToExecute(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: name(other.name), isSigned(other.isSigned),
	  gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form& Form::operator=(const Form& other) {
	if (this != &other)
		isSigned = other.isSigned;
	return *this;
}

Form::~Form() {}

const std::string& Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getGradeToSign() const { return gradeToSign; }
int Form::getGradeToExecute() const { return gradeToExecute; }

void Form::beSigned(const Bureaucrat& b) {
	if(isSigned)
		throw std::runtime_error("Form is already signed");
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form: Grade too high!";
}
const char* Form::GradeTooLowException::what() const throw() {
	return "Form: Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "Form \"" << f.getName() << "\", Signed: " << (f.getIsSigned() ? "yes" : "no")
	   << ", Grade to sign: " << f.getGradeToSign()
	   << ", Grade to execute: " << f.getGradeToExecute();
	return os;
}
