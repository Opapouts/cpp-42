/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:27:46 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/21 18:28:13 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void) {
	std::cout << "----Stack zombies instantiated in the main----\n";
	Zombie A("John");
	A.announce();
	Zombie B("Foo");
	B.announce();
	Zombie* C;
	std::cout << "----Zombie instantiated in the newZombie function----\n";
	C = newZombie("Heap zombie");
	C->announce();
	std::cout << "----Zombie instantiated in the randomChump function----\n";
	randomChump("Trump");
	delete C;
	return (0);
}

