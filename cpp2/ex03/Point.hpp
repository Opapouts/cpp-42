/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:20:07 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/30 16:21:35 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class	Point {

	public :
		Point(void);
		Point(const Fixed a, const Fixed b);
		Point(const Point& other);
		Point& operator = (const Point& other);
		bool	operator == (const Point& other) const;
		~Point(void);
		Fixed	getX(void) const;
		Fixed	getY(void) const;
	private :
		const Fixed	_x;
		const Fixed	_y;
};

#endif
