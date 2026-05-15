/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 20:03:33 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/09 20:03:35 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"
#include <iostream>

//Constructors && Destructor
AMateria::AMateria(void) {
	return ;
}
AMateria::AMateria(std::string const& type) : _type(type) {
	return ;
}
AMateria::AMateria(const AMateria& other) : _type(other._type) {
	return ;
}
AMateria::~AMateria(void) {
	return ;
}

//Operator overload
AMateria&	AMateria::operator = (const AMateria& other) {
	if (this == &other)
		return (*this);
	return (*this);
}

//Function members
std::string const&	AMateria::getType(void) const {
	return (_type);
}
void	AMateria::use(ICharacter& target) {
	std::cout << "An AMateria object used their skill against " << target.getName() << std::endl;
	return ;
}
