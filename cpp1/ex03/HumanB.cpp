/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:40:57 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/22 17:40:59 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <string>
#include <iostream>

//Constructors && Destructors
HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {
	std::cout << this->_name << " of class HumanB instantiated" << std::endl;
	return ;
}
HumanB::~HumanB(void) {
	return ;
}

//Member functions
void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}
void	HumanB::attack(void) {
	if (!this->_weapon)
		std::cout << this->_name << " has no weapon equipped" << std::endl;
	std::cout << this->_name << " attacks with their ";
	std::cout << this->_weapon->getType() << std::endl;
}
