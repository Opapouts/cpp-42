/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:58:47 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/03 19:58:49 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int	main(void) {
	ClapTrap	*a = new ScavTrap("Scav");
	ClapTrap	*b = new FragTrap("Frag");
	ClapTrap	*c = new DiamondTrap("Diamond");

	std::cout << std::endl;
	std::cout << "--------------------Experimenting with ScavTrap named Scam--------------------" << std::endl;
	dynamic_cast<ScavTrap *>(a)->guardGate();
	a->attack("target");
	std::cout << std::endl;
	std::cout << "--------------------Experimenting with FragTrap named Frag--------------------" << std::endl;
	dynamic_cast<FragTrap *>(b)->highFivesGuys();
	b->attack("target");
	std::cout << std::endl;
	std::cout << "--------------------Experimenting with DiamondTrap named Diamond--------------------" << std::endl;
	dynamic_cast<ScavTrap *>(c)->guardGate();
	dynamic_cast<FragTrap *>(c)->highFivesGuys();
	dynamic_cast<DiamondTrap *>(c)->whoAmI();
	c->attack("target");
	std::cout << std::endl;
	std::cout << "--------------------Calling destructors--------------------" << std::endl;
	delete	a;
	delete	b;
	delete	c;
	return (0);
}
