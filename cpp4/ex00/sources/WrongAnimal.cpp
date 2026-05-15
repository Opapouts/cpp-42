/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 18:04:00 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/06 18:04:25 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/WrongAnimal.hpp"
#include <iostream>

//Constructors && Destructor
WrongAnimal::WrongAnimal(void) {
	std::cout << "Default wrong animal created" << std::endl;
	return ;
}
WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "Typed wrong animal created" << std::endl;
	return ;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
	std::cout << "Copy wrong animal created" << std::endl;
	return ;
}
WrongAnimal::~WrongAnimal(void) {
	std::cout << "Wrong animal destroyed" << std::endl;
	return ;
}

//Operator overload
WrongAnimal&	WrongAnimal::operator = (const WrongAnimal& other) {
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

//Member functions
void	WrongAnimal::makeSound(void) const {
	std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << std::endl;
	return ;
}
std::string	WrongAnimal::getType(void) const {
	return (_type);
}
