/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:19:48 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/30 16:19:50 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

//Constructors && Destructor
Fixed::Fixed(void) :_value(0)  {
}
Fixed::Fixed(const Fixed& other) {
	*this = other;
}
Fixed::Fixed(const int number) {
	this->_value = number << _bits;
}
Fixed::Fixed(const float number) {
	this->_value = roundf(number *(1 << _bits));
}

Fixed::~Fixed(void) {
}

//Member functions
int	Fixed::getRawBits(void) const {

	return (this->_value);
}
void	Fixed::setRawBits(int const raw) {
	this->_value = raw;
}
float	Fixed::toFloat(void) const {
	return ((float)this->_value / (1 << _bits));
}
int	Fixed::toInt(void) const {
	return (this->_value >> _bits);
}

//Operator overloads
Fixed&	Fixed::operator = (const Fixed& other) {
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}
bool	Fixed::operator > (const Fixed& other) const {
	if (this->_value > other._value)
		return (true);
	else
		return (false);
}
bool	Fixed::operator < (const Fixed& other) const {
	if (this->_value < other._value)
		return (true);
	else
		return (false);
}
bool	Fixed::operator >= (const Fixed& other) const {
	if (this->_value >= other._value)
		return (true);
	else
		return (false);
}
bool	Fixed::operator <= (const Fixed& other) const {
	if (this->_value <= other._value)
		return (true);
	else
		return (false);
}
bool	Fixed::operator == (const Fixed& other) const {
	if (this->_value == other._value)
		return (true);
	else
		return (false);
}
bool	Fixed::operator != (const Fixed& other) const {
	if (this->_value != other._value)
		return (true);
	else
		return (false);
}
Fixed	Fixed::operator + (const Fixed& other) const {
	return (Fixed(this->toFloat() + other.toFloat()));
}
Fixed	Fixed::operator - (const Fixed& other) const {
	return (Fixed(this->toFloat() - other.toFloat()));
}
Fixed	Fixed::operator * (const Fixed& other) const {
	return (Fixed(this->toFloat() * other.toFloat()));
}
Fixed	Fixed::operator / (const Fixed& other) const {
	return (Fixed(this->toFloat() / other.toFloat()));
}
Fixed&	Fixed::operator ++(void) {
	this->_value++;
	return (*this);
}
Fixed	Fixed::operator ++(int) {
	Fixed	tmp(*this);
	this->_value++;
	return (tmp);
}
Fixed&	Fixed::operator --(void) {
	this->_value--;
	return (*this);
}
Fixed	Fixed::operator --(int) {
	Fixed	tmp(*this);
	this->_value--;
	return (tmp);
}
//Static member functions
Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return ((a < b) ? a : b);
}
const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return ((a < b) ? a : b);
}
Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return ((a > b) ? a : b);
}
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return ((a > b) ? a : b);
}
//Independent function
std::ostream& operator << (std::ostream& stream, Fixed const& object) {
	stream << object.toFloat();
	return stream;
}
