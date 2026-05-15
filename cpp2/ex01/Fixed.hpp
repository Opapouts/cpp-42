/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:36:32 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/28 19:36:34 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class	Fixed {

	public :
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed(const int number);
		Fixed(const float number);
		~Fixed(void);
		Fixed& operator = (const Fixed& other);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;
	private :
		int	_value;
		static int const 	_bits = 8;
};
std::ostream& operator << (std::ostream& o, Fixed const& i);

#endif

