/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:40:04 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/16 18:40:14 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <iostream>

//Constructors && Destructors
AForm::AForm(void): _name("Default"), _isSigned(false), _signGrade(75), _executeGrade(75) {
	return ;
}

AForm::AForm(std::string name): _name(name), _isSigned(false), _signGrade(75), _executeGrade(75) {
	return ;
}

AForm::AForm(std::string name, int signGrade, int executeGrade): _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	return ;
}

AForm::AForm(const AForm& other): _name(other._name), _isSigned(false), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {
	return ;
}

AForm::~AForm(void) {
	return ;
}

//Operator Overloads
AForm&	AForm::operator = (const AForm& other) {
	if (this == &other)
		return (*this);
	_isSigned = other._isSigned;
	return (*this);
}

//name (signed, signGrade, executeGrade)
std::ostream&	operator << (std::ostream& stream, const AForm& other) {
	stream << other.getName() << " (";
	if (other.getIsSigned())
		stream << "true, ";
	else
		stream << "false, ";
	stream << other.getSignGrade() << ", " << other.getExecuteGrade() << ")";
	return (stream);
}

//Member Functions
std::string const& AForm::getName(void) const {
	return (_name);
}

bool	AForm::getIsSigned(void) const {
	return (_isSigned);
}

int	AForm::getSignGrade(void) const {
	return (_signGrade);
}

int	AForm::getExecuteGrade(void) const {
	return (_executeGrade);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

void	AForm::execute(Bureaucrat const& executor) const {
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > _executeGrade)
		throw ExecutionException();
	executeAction();
}

//Exception Classes
const char *AForm::GradeTooHighException::what(void) const throw() {
	return ("Form grade too high, it should be >0");
}

const char *AForm::GradeTooLowException::what(void) const throw() {
	return ("Grade too low");
}

const char *AForm::ExecutionException::what(void) const throw() {
	return ("The form can't be executed, the grade of the bureaucrat is too low");
}

const char *AForm::FormNotSignedException::what(void) const throw() {
	return ("The form is not signed, thus it can't be executed");
}
