/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:45:13 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/03 17:45:15 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {
	ClapTrap	b("Wemby");
	ScavTrap	c("Trump");
	ClapTrap	*poly = new ScavTrap("Inherited");

	b.attack("target");
	c.takeDamage(10);
	c.takeDamage(20);
	c.guardGate();
	c.attack("target");
	c.guardGate();
	c.takeDamage(70);
	static_cast<ScavTrap *>(poly)->guardGate();
	poly->attack("target");
	c.attack("target");
	c.beRepaired(9);
	c.guardGate();
	delete poly;
	return (0);
}
