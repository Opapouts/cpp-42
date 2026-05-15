/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:41:21 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/22 17:41:23 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

//Constructor && Destructor
Weapon::Weapon(std::string type) : _type(type) {
	return ;
}
Weapon::~Weapon(void) {
	return ;
}

//Member functions
const std::string&	Weapon::getType(void) const {
	return (this->_type);
}
void	Weapon::setType(std::string type) {
	this->_type = type;
}
