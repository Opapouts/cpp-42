/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 16:27:45 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/18 16:27:47 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>

//Constructors && Destructor
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Default PPF", 25, 5), _target("Default PPF") {
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade()), _target(other.getTarget()) {
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	return ;
}

//Operator Overload
PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& other) {
	if (this == &other)
		return (*this);
	_target = other.getTarget();
	return (*this);
}

//Member Functions
std::string const& PresidentialPardonForm::getTarget(void) const {
	return (_target);
}

void	PresidentialPardonForm::executeAction(void) const {
	std::cout << _target << " you have been officially pardoned by his majesty Zaphod Beeblebrox" << std::endl;
}
