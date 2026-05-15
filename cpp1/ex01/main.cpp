/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 21:49:33 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/21 21:49:51 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

int	main(int ac, char **av) {
	if (ac != 3) {
		std::cout << "Wrong number of arguments, try with 3" << std::endl;
		return (1);
	}
	std::string	arg1 = av[1];
	std::string	arg2 = av[2];
	for (size_t i = 0; i < arg1.length(); i++) {
		if (!std::isdigit(arg1[i])) {
			std::cout << "Wrong input. Av[1] needs to be a positive number\n";
			return (1);
		}
	}
	int	number = atoi(av[1]);
	Zombie A;
	Zombie B;
	std::cout << "----Zombies instantiated in main----\n";
	A.setName("John");
	A.announce();
	B.setName("Foo");
	B.announce();
	std::cout << std::endl;
	std::cout <<"----Zombies instantiated in zombieHorde----\n";
	Zombie* C;
	C = zombieHorde(number, arg2);
	for (int i = 0; i < number; i++)
		C[i].announce();
	std::cout << std::endl;
	std::cout <<"----Delete and Destructors called----\n";
	delete [] C;
	return (0);
}
