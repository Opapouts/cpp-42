/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:40:45 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/22 17:41:37 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <string>
#include <iostream>

//Constructors && Destructors
HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon), _name(name) {
	std::cout << this->_name << " of class HumanA instantiated" << std::endl;
	return ;
}
HumanA::~HumanA(void) {
	return ;
}

//Member functions
void	HumanA::attack(void) {
	std::cout << this->_name << " attacks with their ";
	std::cout << this->_weapon.getType() << std::endl;
}
