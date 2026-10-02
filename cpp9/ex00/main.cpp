/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 22:08:14 by opapouts          #+#    #+#             */
/*   Updated: 2026/08/03 22:08:15 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int ac, char **av) {
	if (ac == 1) {
		try {
			BitcoinExchange	empty;
			empty.mapLookUp();
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		return (0);
	}
	if (ac > 2)
		return (std::cerr << "Too many arguments" << std::endl, 0);
	try {
		BitcoinExchange	a(av[1]);
		a.mapLookUp();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
