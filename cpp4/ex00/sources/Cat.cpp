/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:22:05 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/06 17:22:07 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include <iostream>

//Constructors && Destructor
Cat::Cat(void) : Animal() {
	std::cout << "Default cat created" << std::endl;
	return ;
}
Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Typed cat created" << std::endl;
	return ;
}
Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Copy cat created" << std::endl;
	return ;
}
Cat::~Cat(void) {
	std::cout << "Cat destroyed" << std::endl;
	return ;
}

//Operator overload
Cat&	Cat::operator = (const Cat& other) {
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

//Member functions
void	Cat::makeSound(void) const {
	std::cout << "Miaou miaou" << std::endl;
}
