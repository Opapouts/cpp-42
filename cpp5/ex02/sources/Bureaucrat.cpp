/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:40:24 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/16 18:40:33 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include <iostream>

//Constructors && Destructors
Bureaucrat::Bureaucrat(void): _name("Default"), _grade(150) {
	return ;
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(150) {
	return ;
}

Bureaucrat::Bureaucrat(int grade): _name("Unamed"), _grade(grade) {
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade) {
	return ;
}

Bureaucrat::~Bureaucrat(void) {
	return ;
}

//Operator overloads
Bureaucrat&	Bureaucrat::operator = (const Bureaucrat& other) {
	if (this == &other)
		return (*this);
	_grade = other._grade;
	return (*this);
}

std::ostream&	operator << (std::ostream& stream, const Bureaucrat& other) {
	stream << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
	return (stream);
}

//Member Functions
std::string const& Bureaucrat::getName(void) const {
	return (_name);
}

int	Bureaucrat::getGrade(void) const {
	return (_grade);
}

void	Bureaucrat::increaseGrade(void) {
	if (_grade == 1)
		throw GradeTooHighException();
	_grade-- ;
}

void	Bureaucrat::decreaseGrade(void) {
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(AForm& form) {
	if (form.getIsSigned()) {
		std::cout << getName() << " couldn't sign " << form.getName() << " because it was already signed" << std::endl;
		return ;
	}
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed form " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << getName() << " couldn't sign " << form.getName() << " because grade was too low" << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const& form) const {
	try {
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

//Exception classes
const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Grade too high, it should be >0");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Grade too low, it should be <151");
}
