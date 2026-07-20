/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:26:56 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/18 18:27:01 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main(void) {
	std::srand(std::time(NULL));
	std::cout << "===============" << std::endl;
	std::cout << "Simple tests" << std::endl;
	std::cout << "===============" << std::endl;
	std::cout << std::endl;

	Bureaucrat	junior("Junior", 140);
	Bureaucrat	senior("Senior", 30);
	Bureaucrat	ceo("CEO", 1);
	ShrubberyCreationForm	scf("scf");
	RobotomyRequestForm	rrf("rrf");
	PresidentialPardonForm	ppf("ppf");

	try {
		junior.signForm(scf);
		senior.executeForm(scf);
		senior.signForm(rrf);
		senior.executeForm(rrf);
		ceo.signForm(ppf);
		ceo.executeForm(ppf);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===============" << std::endl;
	std::cout << "Signature errors" << std::endl;
	std::cout << "===============" << std::endl;
	std::cout << std::endl;

	Bureaucrat	random("Random", 150);
	ShrubberyCreationForm	a("scf");
	RobotomyRequestForm	b("rrf");
	PresidentialPardonForm	c("ppf");

	try {
		random.signForm(a);
		junior.signForm(b);
		senior.signForm(c);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===============" << std::endl;
	std::cout << "Execution errors" << std::endl;
	std::cout << "===============" << std::endl;
	std::cout << std::endl;

	PresidentialPardonForm	notsigned("notsigned");

	try {
		junior.executeForm(scf);
		senior.executeForm(ppf);
		ceo.executeForm(notsigned);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
