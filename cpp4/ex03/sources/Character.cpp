/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 02:26:59 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/11 02:27:03 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include <iostream>

//Constructors && Destructors
Character::Character(void): _name("default") {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	return ;
}
Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	return ;
}
Character::Character(const Character& other) : _name(other._name) {
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	return ;
}
Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
	return ;
}

//Operator overload
Character&	Character::operator = (const Character& other) {
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	_name = other._name;
	return (*this);
}

//Function members
std::string const&	Character::getName(void) const {
	return (_name);
}
void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4 ; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Inventory of " << _name << " already full" << std::endl;
	return ;
}
void	Character::unequip(int idx) {
	if (idx > 3 || idx < 0) {
		std::cout << "Wrong index, use an index from 0 to 3" << std::endl;
		return ;
	}
	_inventory[idx] = NULL;
	return ;
}
void	Character::use(int idx, ICharacter& target) {
	if (idx > 3 || idx < 0) {
		std::cout << "Wrong index, use an index from 0 to 3" << std::endl;
		return ;
	}
	if (_inventory[idx])
		_inventory[idx]->use(target);
	return ;
}
