/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:35:03 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/16 16:35:08 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include <iostream>

int	main(void) {
	std::cout << "===============" << std::endl;
	std::cout << "First tests" << std::endl;
	std::cout << "===============" << std::endl;
	std::cout << std::endl;

	try {
		Bureaucrat Bellingham("Bellingham", 2);
		Form	a("ENG", 10, 10);
		Bureaucrat Digne("Digne", 149);
		Form	b("FR", 50, 50);
		std::cout << "Form info-> " << a << std::endl;
		std::cout << "Form info-> " << b << std::endl;
		Bellingham.signForm(a);
		Digne.signForm(b);
		std::cout << "This should be printed" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "===============" << std::endl;
	std::cout << "Second tests" << std::endl;
	std::cout << "===============" << std::endl;
	std::cout << std::endl;
	
	try {
		Bureaucrat Barcola("Barcola", 15);
		Form	c("jsp", 15, 15);
		Bureaucrat Haaland("Haaland", 1);
		std::cout << "Form info-> " << c << std::endl;
		Barcola.signForm(c);
		Haaland.signForm(c);
		std::cout << "This should be printed" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "===============" << std::endl;
	std::cout << "Initialisation test" << std::endl;
	std::cout << "===============" << std::endl;
	std::cout << std::endl;

	try {
		Bureaucrat Lamine("Lamine", 5);
		Form d("ESP", 5, 5);
		std::cout << "Form info-> " << d << std::endl;
		Form e("FAIL", 151, 100);
		std::cout << "this shouldn't be printed" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
