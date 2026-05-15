/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:25:47 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/03 17:26:55 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

//Constructors && Destructors
ScavTrap::ScavTrap(void) : ClapTrap(), _gateMode(false) {
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << "======>";
	std::cout << "The default constructor of class ScavTrap has been called" << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _gateMode(false) {
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << "======>";
	std::cout << this->_name << " of the class ScavTrap has been instantiated" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	_gateMode = other._gateMode;
	std::cout << "======>";
	std::cout << "Copy constructor of the class ScavTrap has been instantiated" << std::endl;
}
ScavTrap::~ScavTrap(void) {
	std::cout << "======>";
	std::cout << this->_name << " has been destroyed" << std::endl;
}

//Operaton overload
ScavTrap&	ScavTrap::operator = (const ScavTrap& other) {
	if (this == &other)
		return (*this);
	_name = other._name;
	_hp = other._hp;
	_ep = other._ep;
	_ad = other._ad;
	_gateMode = other._gateMode;
	std::cout << "Copy assignation operator has been called" << std::endl;
	return (*this);
}
//Member functions
void	ScavTrap::guardGate(void) {
	if (this->_hp > 0 && this->_ep > 0 && !this->_gateMode) {
		this->_gateMode = true;
		this->_ep--;
		std::cout << this->_name << " is now in Gate keeper mode!" << std::endl;
	}
	else if (this->_hp > 0 && this->_ep > 0 && this->_gateMode) {
		this->_gateMode = false;
		std::cout << this->_name << " is not in Gate keeper mode anymore!" << std::endl;
	}
	else
		std::cout << this->_name << " can't use guardGate, he is either dead or has no energy points" << std::endl;
}
void	ScavTrap::attack(const std::string& target) {
	if (this->_hp > 0 && this->_ep > 0 && !this->_gateMode) {
		this->_ep--;
		std::cout << this->_name << " dealt " << this->_ad << " dmg to " << target << std::endl;
	}
	else
		std::cout << this->_name << " can't attack, he is either dead, has no energy points or in Gate keeper mode!" << std::endl;
}
