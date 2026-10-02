/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:42:59 by opapouts          #+#    #+#             */
/*   Updated: 2026/08/05 17:43:00 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int	main(int ac, char **av) {
	if (!ac) {
		std::cout << "Please input a positive integer sequence" << std::endl;
		return (1);
	}

	PmergeMe	a;
	std::string input;

	for (int i = 1; av[i]; ++i) {
		input +=av[i];
		if (av[i + 1] != NULL)
			input += " ";
	}
	try {
		a.run(input);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	return (0);
}
