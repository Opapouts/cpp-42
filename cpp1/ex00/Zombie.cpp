/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:27:51 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/21 18:27:52 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

//Constructor && Destructor
Zombie::Zombie(std::string name) {
	this->_name = name;
	return ;
}
Zombie::~Zombie(void) {
	std::cout << this->_name << " is destroyed\n";
	return ;
}

//Member functions
void	Zombie::announce(void) const {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}
