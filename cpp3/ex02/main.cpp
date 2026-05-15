/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:36:29 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/03 19:36:30 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	ClapTrap	*a = new ScavTrap("Inherited");
	ClapTrap	*w = new FragTrap("Frag");
	ClapTrap	b("Wemby");
	ScavTrap	c("Trump");

	static_cast<FragTrap *>(w)->highFivesGuys();
	w->attack("target");
	c.attack("target");
	static_cast<ScavTrap *>(a)->guardGate();
	a->attack("target");
	c.takeDamage(10);
	c.guardGate();
	c.attack("target");
	c.guardGate();
	c.takeDamage(70);
	delete	w;
	delete a;
	return (0);
}
