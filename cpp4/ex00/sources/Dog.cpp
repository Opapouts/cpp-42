/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:21:54 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/06 17:22:15 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include <iostream>

//Constructors && Destructor
Dog::Dog(void) : Animal() {
	std::cout << "Default dog created" << std::endl;
	return ;
}
Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Typed dog created" << std::endl;
	return ;
}
Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Copy dog created" << std::endl;
	return ;
}
Dog::~Dog(void) {
	std::cout << "Dog destroyed" << std::endl;
	return ;
}

//Operator overload
Dog&	Dog::operator = (const Dog& other) {
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

//Member functions
void	Dog::makeSound(void) const {
	std::cout << "Wooof wooof" << std::endl;
}
