/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:07:23 by opapouts          #+#    #+#             */
/*   Updated: 2026/08/04 16:07:25 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error" << std::endl;
		return (0);
	}
	RPN	a;
	try {
		a.readInput(av[1]);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
