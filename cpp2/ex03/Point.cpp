/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:19:39 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/30 16:20:53 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//Constructors && Destructors
Point::Point(void) : _x(0), _y(0) {
	return ;
}
Point::Point(const Fixed a, const Fixed b) : _x(a.toFloat()), _y(b.toFloat()) {
	return ;
}
Point::Point(const Point& other) : _x(other._x), _y(other._y) {
	return ;
}
Point::~Point(void) {
	return ;
}
//Member functions
Fixed	Point::getX(void) const {
	return (this->_x);
}
Fixed	Point::getY(void) const {
	return (this->_y);
}

//Operator overloads
Point&	Point::operator = (const Point& other) {
	(void) other;
	return (*this);
}
bool	Point::operator == (const Point& other) const {
	if (this->_x == other._x && this->_y == other._y)
		return (true);
	else
		return (false);
}
