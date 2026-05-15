/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:59:35 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/03 19:59:41 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

//Constructors && Destructors
DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap() {
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_ad = FragTrap::_ad;
	std::cout << "++++++>";
	std::cout << "The default constructor of class DiamondTrap has been called" << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 30;
	ClapTrap::_name = name + "_clap_name";
	std::cout << "++++++>";
	std::cout << this->_name << " of the class DiamondTrap has been instantiated" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	*this = other;
	std::cout << "++++++>";
	std::cout << "Copy constructor of the class FragTrap has been instantiated" << std::endl;
}
DiamondTrap::~DiamondTrap(void) {
	std::cout << "++++++>";
	std::cout << this->_name << " has been destroyed" << std::endl;
}

//Operaton overload
DiamondTrap&	DiamondTrap::operator = (const DiamondTrap& other) {
	if (this == &other)
		return (*this);
	_name = other._name;
	_hp = other._hp;
	_ep = other._ep;
	_ad = other._ad;
	std::cout << "Copy assignation operator has been called" << std::endl;
	return (*this);
}
//Member functions
void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}
void	DiamondTrap::whoAmI(void) {
	std::cout << "ClapTrap name is -> " << ClapTrap::_name << std::endl;
	std::cout << "DiamondTrap name is -> " << this->_name << std::endl;
}

