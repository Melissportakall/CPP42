/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:34:23 by melisportak       #+#    #+#             */
/*   Updated: 2025/05/15 12:34:24 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Untitled"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeSign, int gradeExec)
	: name(name), isSigned(false), gradeToSign(gradeSign), gradeToExecute(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: name(other.name), isSigned(other.isSigned),gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		isSigned = other.isSigned;
	return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Form: Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Form: Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form: Not signed!";
}

void AForm::Execheck(const Bureaucrat& executor) const {
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
}
std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << "Form \"" << f.getName() << "\", Signed: " << (f.getIsSigned() ? "yes" : "no")
	   << ", Grade to sign: " << f.getGradeToSign()
	   << ", Grade to execute: " << f.getGradeToExecute();
	return os;
}


