/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:58:25 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/20 17:58:28 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main(void) {
	std::srand(std::time(NULL));
	std::cout << "===============" << std::endl;
	std::cout << "Simple tests" << std::endl;
	std::cout << "===============" << std::endl;
	std::cout << std::endl;
	
	Bureaucrat	bossman("bossman", 1);
	Intern		a;

	AForm *scf = a.makeForm("shrubbery creation", "random target");
	AForm *rrf = a.makeForm("robotomy request", "john");
	AForm *ppf = a.makeForm("presidential pardon", "mbappe");
	bossman.signForm(*scf);
	bossman.signForm(*rrf);
	bossman.signForm(*ppf);
	bossman.executeForm(*scf);
	bossman.executeForm(*rrf);
	bossman.executeForm(*ppf);
	delete scf;
	delete rrf;
	delete ppf;

	std::cout << std::endl;
	std::cout << "===============" << std::endl;
	std::cout << "Invalid tests" << std::endl;
	std::cout << "===============" << std::endl;
	std::cout << std::endl;

	AForm *fail1 = a.makeForm("haaland", "ENG");
	AForm *fail2 = a.makeForm("Harry Kane", "JSP");
	(void) fail1;
	(void) fail2;

	return (0);
}
