/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:57:59 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/03 19:58:51 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

//Constructor && Destructor
ClapTrap::ClapTrap(void) : _name("Default"), _hp(10), _ep(10), _ad(0) {
	std::cout << "------>";
	std::cout << "The default class of the class ClapTrap has been called" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0) {
	std::cout << "------>";
	std::cout << this->_name << " of the class ClapTrap has been instantiated" << std::endl;
	return ;
}
ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hp(other._hp), _ep(other._ep), _ad(other._ad) {
	std::cout << "------>";
	std::cout << this->_name << " of the class ClapTrap has been instantiated" << std::endl;
	return ;
}
ClapTrap::~ClapTrap(void) {
	std::cout << "------>";
	std::cout << this->_name << " has beed destroyed" << std::endl;
	return ;
}

//Operator overload
ClapTrap&	ClapTrap::operator = (const ClapTrap& other) {
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_ad = other._ad;
	return (*this);
}

//Member functions
void	ClapTrap::attack(const std::string& target) {
	if (this->_ep > 0 && this->_hp > 0) {
	std::cout << "ClapTrap " << this->_name << " attacks " << target<< " causing " << this->_ad <<" points of damage!" <<std::endl;
	this->_ep--;
	}
	else if (!this->_ep)
		std::cout << "ClapTrap " << this->_name << " has no energy points to attack" << std::endl;
	else if (!this->_hp)
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
}
void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hp <= 0) {
		std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " has taken " << amount <<" points of damage!" << std::endl;
	this->_hp -= amount;
	if (this->_hp <= 0) {
		this->_hp = 0;
		std::cout << "ClapTrap " << this->_name << " died" << std::endl;
	}
}
void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_ep > 0 && this->_hp > 0) {
		std::cout << "ClapTrap " << this->_name << " has restored " << amount << " hp!" << std::endl;
	this->_hp += amount;
	this->_ep--;
	}
	else if (!this->_ep)
		std::cout << "ClapTrap " << this->_name << " has no energy points to heal" << std::endl;
	else if (!this->_hp)
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
}
