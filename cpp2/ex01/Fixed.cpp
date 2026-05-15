/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:36:28 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/28 19:36:29 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

//Constructors && Destructor
Fixed::Fixed(void) :_value(0)  {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}
Fixed::Fixed(const int number) {
	this->_value = number << _bits;
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float number) {
	this->_value = roundf(number *(1 << _bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

//Member functions
int	Fixed::getRawBits(void) const {

	return (this->_value);
}
void	Fixed::setRawBits(int const raw) {
	this->_value = raw;
}
Fixed&	Fixed::operator = (const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}
float	Fixed::toFloat(void) const {
	return ((float)this->_value / (1 << _bits));
}
int	Fixed::toInt(void) const {
	return (this->_value >> _bits);
}
//Independent function
std::ostream& operator << (std::ostream& stream, Fixed const& object) {
	stream << object.toFloat();
	return stream;
}

