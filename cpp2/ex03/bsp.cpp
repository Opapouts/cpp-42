/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:20:16 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/30 16:20:17 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//Area=∣(x1(y2−y3)+x2(y3−y1)+x3(y1−y2))/2∣ The formula used to calculate the 
//area of a triangle

static Fixed	calculateArea(Point const a, Point const b, Point const c) {
	Fixed	doubleArea;

	doubleArea = a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY());
	if (doubleArea < 0)
		doubleArea = doubleArea * -1;
	return (doubleArea);
}
	

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	abpoint;
	Fixed	acpoint;
	Fixed	bcpoint;
	Fixed	abc;

	abpoint = calculateArea(a, b, point);
	acpoint = calculateArea(a, c, point);
	bcpoint = calculateArea(b, c, point);
	abc = calculateArea(a, b, c);
	if (abpoint == 0 || acpoint == 0 || bcpoint == 0 || abc == 0)
		return (false);
	else if (abpoint + acpoint + bcpoint == abc)
		return (true);
	else
		return (false);
}
