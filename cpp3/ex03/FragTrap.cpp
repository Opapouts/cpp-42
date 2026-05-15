/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:58:15 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/03 19:58:17 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

//Constructors && Destructors
FragTrap::FragTrap(void) : ClapTrap() {
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << "******>";
	std::cout << "The default constructor of class FragTrap has been called" << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << "******>";
	std::cout << this->_name << " of the class FragTrap has been instantiated" << std::endl;
}
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "******>";
	std::cout << "Copy constructor of the class FragTrap has been instantiated" << std::endl;
}
FragTrap::~FragTrap(void) {
	std::cout << "******>";
	std::cout << this->_name << " has been destroyed" << std::endl;
}

//Operaton overload
FragTrap&	FragTrap::operator = (const FragTrap& other) {
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
void	FragTrap::attack(const std::string& target) {
	if (this->_ep > 0 && this->_hp > 0) {
	std::cout << "FragTrap " << this->_name << " attacks " << target<< " causing " << this->_ad <<" points of damage!" <<std::endl;
	this->_ep--;
	}
	else if (!this->_ep)
		std::cout << "FragTrap " << this->_name << " has no energy points to attack" << std::endl;
	else if (!this->_hp)
		std::cout << "FragTrap " << this->_name << " is dead" << std::endl;
}
void	FragTrap::highFivesGuys(void) {
	std::cout << this->_name << " puts his hands in the air and asks for a high five";
	std::cout << std::endl;
}

