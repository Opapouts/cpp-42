/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:30:34 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/27 17:30:34 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

//Constructor && Destructor
Fixed::Fixed(void) :_value(0)  {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

//Member functions
int	Fixed::getRawBits(void) const {

	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}
void	Fixed::setRawBits(int const raw) {
	this->_value = raw;
}
Fixed&	Fixed::operator = (const Fixed& other) {
	std::cout << "Copy assignment Operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}
