/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 19:51:08 by opapouts          #+#    #+#             */
/*   Updated: 2026/07/20 19:51:09 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Please use only 1 input" << std::endl;
		std::cerr << "The input shoudl look like this, ./convert <literal>" << std::endl;
		return (0);
	}
	std::string	literal = av[1];
	ScalarConverter::convert(literal);
	return (0);
}
