/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 21:49:39 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/21 21:49:40 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

//Constructor && Destructor
Zombie::Zombie(void) {
	return ;
}
Zombie::~Zombie(void) {
	std::cout << this->_name << " is destroyed\n";
	return ;
}

//Member functions
void	Zombie::setName(std::string name) {
	this->_name = name;
}
void	Zombie::announce(void) const {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}
