/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 17:59:01 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/12 17:59:12 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main(void) {
	std::cout << "===============" << std::endl;
	std::cout << "Valid tests" << std::endl;
	std::cout << "===============" << std::endl;
	std::cout << std::endl;

	try {
		Bureaucrat a("Olise", 2);
		a.increaseGrade();
		std::cout << a << "is the goat" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat b("Mbappe", 1);
		b.decreaseGrade();
		std::cout << b << "le football il a change" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "===============" << std::endl;
	std::cout << "Invalid tests" << std::endl;
	std::cout << "===============" << std::endl;
	std::cout << std::endl;

	try {
		Bureaucrat c("Pessi", 150);
		std::cout << "We will try to decrease the grade to 151" << std::endl;
		c.decreaseGrade();
		std::cout << "If this was printed, then there was an error" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat d("Jude", 1);
		std::cout << "We will try to increase the grade to 0" << std::endl;
		d.increaseGrade();
		std::cout << "If this was printed, then there was an error" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "We will try to create an object with a grade of 155" << std::endl;
		Bureaucrat e("Paraguay", 155);
		e.increaseGrade();
		std::cout << "If this was printed, then there was an error" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
