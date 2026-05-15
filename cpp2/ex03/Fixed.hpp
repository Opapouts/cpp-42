/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:19:57 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/30 16:19:59 by opapouts         ###   ########.fr       */
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
		bool operator > (const Fixed& other) const;
		bool operator < (const Fixed& other) const;
		bool operator >= (const Fixed& other) const;
		bool operator <= (const Fixed& other) const;
		bool operator == (const Fixed& other) const;
		bool operator != (const Fixed& other) const;
		Fixed operator + (const Fixed& other) const;
		Fixed operator - (const Fixed& other) const;
		Fixed operator * (const Fixed& other) const;
		Fixed operator / (const Fixed& other) const;
		Fixed& operator ++(void);
		Fixed operator ++(int);
		Fixed& operator --(void);
		Fixed operator --(int);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;
		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static	Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
	private :
		int	_value;
		static int const 	_bits = 8;
};
std::ostream& operator << (std::ostream& o, Fixed const& i);

#endif

