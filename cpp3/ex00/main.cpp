/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:31:42 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/01 19:31:43 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	a("John");
	ClapTrap	b("Wemby");
	ClapTrap	c("Trump");

	a.attack("target");
	b.attack("target");
	c.takeDamage(4);
	c.takeDamage(7);
	c.takeDamage(4);
	c.beRepaired(9);
	c.takeDamage(4);
	return (0);
}

