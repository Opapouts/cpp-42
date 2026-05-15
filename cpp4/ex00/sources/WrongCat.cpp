/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 18:04:16 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/06 18:04:18 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"
#include <iostream>

//Constructors && Destructor
WrongCat::WrongCat(void) : WrongAnimal() {
	std::cout << "Default wrong cat created" << std::endl;
	return ;
}
WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
	std::cout << "Typed wrong cat created" << std::endl;
	return ;
}
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "Copy wrong cat created" << std::endl;
	return ;
}
WrongCat::~WrongCat(void) {
	std::cout << "Wrong cat destroyed" << std::endl;
	return ;
}

//Operator overload
WrongCat&	WrongCat::operator = (const WrongCat& other) {
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

//Member functions
void	WrongCat::makeSound(void) const {
	std::cout << "I am a wrong cat" << std::endl;
}
