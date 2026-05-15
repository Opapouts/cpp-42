/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 18:12:59 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/08 18:13:00 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"
#include <iostream>

//Constructors && Destructor
Ice::Ice(void) : AMateria("ice") {
	return ;
}
Ice::Ice(const Ice& other) : AMateria(other) {
	_type = other._type;
	return ;
}
Ice::~Ice(void) {
	return ;
}

//Operator overload
Ice&	Ice::operator = (const Ice& other) {
	if (this == &other)
		return (*this);
	return (*this);
}

//Function Members
AMateria*	Ice::clone(void) const {
	return (new Ice(*this));
}
void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}
