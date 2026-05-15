/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 20:56:31 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/07 20:56:36 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include <iostream>

//Constructors && Destructor
Animal::Animal(void) {
	std::cout << "Default animal created" << std::endl;
	return ;
}
Animal::Animal(std::string type) : _type(type) {
	std::cout << "Typed animal created" << std::endl;
	return ;
}
Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout << "Copy animal created" << std::endl;
	return ;
}
Animal::~Animal(void) {
	std::cout << "Animal destroyed" << std::endl;
	return ;
}

//Operator overload
Animal&	Animal::operator = (const Animal& other) {
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

//Member functions
std::string	Animal::getType(void) const {
	return (_type);
}
