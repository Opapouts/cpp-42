/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 16:00:32 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/18 16:00:33 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

//Constructors && Destructor
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Default RRF", 72, 45), _target("Default RRF") {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade()), _target(other.getTarget()) {
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	return ;
}

//Operator Overload
RobotomyRequestForm&  RobotomyRequestForm::operator = (const RobotomyRequestForm& other) {
	if (this == &other)
		return (*this);
	_target = other.getTarget();
	return (*this);
}

//Member Functions
std::string const& RobotomyRequestForm::getTarget(void) const {
	return (_target);
}

bool	RobotomyRequestForm::robotomize(void) const {
	std::cout << "bzzzz bzzzzz bzzzzzzz" << std::endl;
	if (std::rand() % 2 != 0)
		return (false);
	else
		return (true);
}

void	RobotomyRequestForm::executeAction(void) const {
	if (robotomize())
		std::cout << _target << " you have been robotomized!" << std::endl;
	else
		std::cout << _target << " robotomization has failed!" << std::endl;
}
