/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 19:26:24 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/12 19:26:25 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"
#include <iostream>

//Constructors && Destructors
Form::Form(void): _name("Default"), _isSigned(false), _signGrade(75), _executeGrade(75) {
	return ;
}

Form::Form(std::string name): _name(name), _isSigned(false), _signGrade(75), _executeGrade(75) {
	return ;
}

Form::Form(std::string name, int signGrade, int executeGrade): _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	return ;
}

Form::Form(const Form& other): _name(other._name), _isSigned(false), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {
	return ;
}

Form::~Form(void) {
	return ;
}

//Operator Overloads
Form&	Form::operator = (const Form& other) {
	if (this == &other)
		return (*this);
	_isSigned = other._isSigned;
	return (*this);
}

//name (signed, signGrade, executeGrade)
std::ostream&	operator << (std::ostream& stream, const Form& other) {
	stream << other.getName() << " (";
	if (other.getIsSigned())
		stream << "true, ";
	else
		stream << "false, ";
	stream << other.getSignGrade() << ", " << other.getExecuteGrade() << ")";
	return (stream);
}

//Member Functions
std::string const& Form::getName(void) const {
	return (_name);
}

bool	Form::getIsSigned(void) const {
	return (_isSigned);
}

int	Form::getSignGrade(void) const {
	return (_signGrade);
}

int	Form::getExecuteGrade(void) const {
	return (_executeGrade);
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

//Exception Classes
const char *Form::GradeTooHighException::what(void) const throw() {
	return ("Form grade too high, it should be >0");
}

const char *Form::GradeTooLowException::what(void) const throw() {
	return ("Grade too low");
}
