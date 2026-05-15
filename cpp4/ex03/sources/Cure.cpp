/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 18:12:55 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/11 02:27:11 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"
#include <iostream>

//Constructors && Destructor
Cure::Cure(void) : AMateria("cure") {
	return ;
}
Cure::Cure(const Cure& other) : AMateria(other) {
	_type = other._type;
	return ;
}
Cure::~Cure(void) {
	return ;
}

//Operator overload
Cure&	Cure::operator = (const Cure& other) {
	if (this == &other)
		return (*this);
	return (*this);
}

//Function Members
AMateria*	Cure::clone(void) const {
	return (new Cure(*this));
}
void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}
