/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:18:09 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/18 19:18:14 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"
#include <iostream>

//Constructors && Destructor
Intern::Intern(void) {
	return ;
}

Intern::Intern(const Intern& other) {
	(void) other;
}

Intern::~Intern(void) {
	return ;
}

//Operator Overload
Intern&	Intern::operator = (const Intern& other) {
	(void) other;
	return (*this);
}

//Member Functions
AForm*	Intern::makeShrubbery(const std::string& target) const {
	ShrubberyCreationForm	*form = new ShrubberyCreationForm(target);
	return (form);
}

AForm*	Intern::makeRobotomy(const std::string& target) const {
	RobotomyRequestForm	*form = new RobotomyRequestForm(target);
	return (form);
}

AForm*	Intern::makePresidential(const std::string& target) const {
	PresidentialPardonForm	*form = new PresidentialPardonForm(target);
	return (form);
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target) {
	std::string	forms[3];
	forms[0] = "shrubbery creation";
	forms[1] = "robotomy request";
	forms[2] = "presidential pardon";

	typedef AForm* (Intern::*FormMaker)(const std::string& target) const;

	FormMaker	formMakers[3];
	formMakers[0] = &Intern::makeShrubbery;
	formMakers[1] = &Intern::makeRobotomy;
	formMakers[2] = &Intern::makePresidential;
	for (int i = 0; i < 3; i++) {
		if (name == forms[i]) {
			std::cout << "Intern creates " << name << std::endl;
			return (this->*formMakers[i])(target);
					}
	}
	std::cout << "Instructions unclear, Intern burned the office down" << std::endl;
	return (NULL);
}
